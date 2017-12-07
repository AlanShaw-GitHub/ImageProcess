//
// Created by 肖振新 on 2017/12/6.
//

#include <basic_img.h>

bool IPP_resize(version v,double fx, double fy){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;
    if(fx < 1.0)
        resize(input_img,output_img,Size(),fx,fy,CV_INTER_AREA);
    else
        resize(input_img,output_img,Size(),fx,fy,CV_INTER_LINEAR);

    imwrite(output_path,output_img);

    return true;
}

bool IPP_rotate(version v,double degree){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    int maxlength = max(input_img.cols, input_img.rows);
    Point2f pt(maxlength/2.,maxlength/2.);
    Mat r = getRotationMatrix2D(pt,degree,1.0);
    warpAffine(input_img,output_img,r,Size(maxlength,maxlength));

    imwrite(output_path,output_img);
    return true;
}

bool IPP_blur(version v,int ksize){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;
    if(ksize % 2 == 0)
        ksize++;
    medianBlur(input_img,output_img,ksize);

    imwrite(output_path,output_img);
    return true;
}

bool IPP_sobel(version v){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    Mat input_img_gray;
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    int ddepth = CV_16S;
    int scale = 1;
    int delta = 0;
    GaussianBlur( input_img, input_img, Size(3,3), 0, 0, BORDER_DEFAULT );
    cvtColor( input_img, input_img_gray, CV_RGB2GRAY );
    Sobel( input_img_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    Sobel( input_img_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, output_img );

    imwrite(output_path,output_img);
    return true;
}


bool IPP_hist(version v){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = "./temp/hist.jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;


    int channels[3] = { 0,1,2 };
    //输出直方图
    Mat red, green, blue;
    //维数
    int dims = 1;
    //存放每个维度直方图尺寸（bin数量）的数组histSize
    int histSize[3] = { 256,256,256 };
    //每一维数值的取值范围ranges
    float hranges[2] = { 0, 255 };
    //值范围的指针
    const float *ranges[3] = { hranges,hranges,hranges};

    //R
    calcHist(&input_img, 1, &channels[0], Mat(),
                 red, dims, &histSize[0], &ranges[0]);
    //G
    calcHist(&input_img, 1, &channels[1], Mat(),
                 green, dims, &histSize[1], &ranges[1]);
    //B
    calcHist(&input_img, 1, &channels[2], Mat(),
                 blue, dims, &histSize[2], &ranges[2]);

    Mat output_red(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    Mat output_green(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    Mat output_blue(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    double maxValue[3] = { 0, 0, 0 };
    double minValue[3] = { 0, 0, 0 };
    minMaxLoc(red, &minValue[0], &maxValue[0]);
    minMaxLoc(green, &minValue[1], &maxValue[1]);
    minMaxLoc(blue, &minValue[2], &maxValue[2]);

    //纵坐标缩放比例
    double rate_red = (histSize[0] / maxValue[0]);
    double rate_green = (histSize[0] / maxValue[1]);
    double rate_blue = (histSize[0] / maxValue[2]);

    for (int i = 0; i < histSize[0]; i++)
    {
        float value_red= red.at<float>(i);
        float value_green = green.at<float>(i);
        float value_blue = blue.at<float>(i);
        line(output_red, Point(i, histSize[0]),
                 Point(i, histSize[0] - value_red*rate_red), Scalar(0,0,255));
        line(output_green, Point((i), histSize[0]),
                 Point((i), histSize[0] - value_green*rate_green), Scalar(0, 255, 0));
        line(output_blue, Point((i), histSize[0]),
                 Point((i), histSize[0] - value_blue*rate_blue), Scalar(255, 0, 0));
    }

    addWeighted(output_red, 0.6, output_green ,0.6, 0.0, output_red);
    addWeighted(output_red, 1.2, output_blue ,0.6,0.0, output_img);

    imwrite(output_path,output_img);
    return true;
}

bool IPP_split(version v,channel c){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;

    if(c != RED && c != GREEN && c != BLUE)
        return false;
    Mat output_img;
    vector<Mat> output_img_array;

    split(input_img,output_img_array);
    if(c == RED){
        output_img_array[0] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
        output_img_array[1] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
    }
    else if(c == GREEN){
        output_img_array[0] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
        output_img_array[2] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
    }
    else if(c == BLUE){
        output_img_array[1] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
        output_img_array[2] = Mat::zeros(input_img.rows,input_img.cols,CV_8UC1);
    }
    merge(output_img_array,output_img);
    imwrite(output_path,output_img);
    return true;
}




bool IPP_brightness(version v, int brightness)
{
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v + 1) + ".jpg";

    Mat img = imread(input_path);
    if (img.empty())
        return false;
    
    Vec3b delta_brightness(brightness, brightness, brightness);

    for (int i = 0; i < img.rows; ++i)
        for (int j = 0; j < img.cols; ++j)
            img.at<Vec3b>(i, j) += delta_brightness;

    imwrite(output_path, img);

    return true;
}

bool IPP_contrast(version v, double contrast_rate)
{
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v + 1) + ".jpg";

    Mat img = imread(input_path);
    if (img.empty())
        return false;

    for (int i = 0; i < img.rows; ++i)
        for (int j = 0; j < img.cols; ++j)
            img.at<Vec3b>(i, j) *= contrast_rate;

    imwrite(output_path, img);

    return true;
}


/*------------templates--------

string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
Mat input_img = imread(input_path);
if(input_img.empty() == true)
return false;
Mat output_img;



imwrite(output_path,output_img);
return true;
*/












