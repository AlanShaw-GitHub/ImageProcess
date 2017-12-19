//
// Created by 肖振新 on 2017/12/6.
//

#include "basic_img.h"

bool IPP_resize(version v,IPP_TYPE type,int percent){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;
    if(type == COMPRESS)
        resize(input_img,output_img,Size(),1-0.009*percent,1-0.009*percent,CV_INTER_AREA);
    else if(type == REBUILD)
        resize(input_img,output_img,Size(),0.1*percent,0.1*percent,CV_INTER_LINEAR);

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
    Point2f pt(input_img.cols/2.,input_img.rows/2.);
    Mat r = getRotationMatrix2D(pt,degree,1.0);
    warpAffine(input_img,output_img,r,Size(input_img.cols, input_img.rows));
    if(static_cast<int>(degree) == 90){
        if(input_img.cols > input_img.rows)
            output_img = output_img.colRange((input_img.cols-input_img.rows)/2,(input_img.cols+input_img.rows)/2);
        else
            output_img = output_img.rowRange((input_img.rows-input_img.cols)/2,(input_img.cols+input_img.rows)/2);
    }
    else {
        if (input_img.cols > input_img.rows) {
            output_img = output_img.colRange(input_img.cols / 2 - 0.35 * input_img.rows,
                                             input_img.cols / 2 + 0.35 * input_img.rows);
            output_img = output_img.rowRange(input_img.rows * 0.147, input_img.rows * 0.852);
        } else {
            output_img = output_img.rowRange(input_img.rows / 2 - 0.35 * input_img.cols,
                                             input_img.rows / 2 + 0.35 * input_img.cols);
            output_img = output_img.colRange(input_img.cols * 0.147, input_img.cols * 0.852);
        }
    }
    imwrite(output_path,output_img);
    return true;
}

bool IPP_cut(version v,int x,int y,int sizex,int sizey){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + string("ROI_") + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    output_img = input_img(Rect(x,y,sizex,sizey));

    imwrite(output_path,output_img);
    return true;
}

bool IPP_csv(version v,IPP_CHANNEL c){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;

    ofstream file;
    vector<Mat> input_img_array;
    split(input_img,input_img_array);
    if(c == RED) {
        file.open("./temp/MAT_R.csv");
        file << input_img_array[2];
    }
    if(c == GREEN) {
        file.open("./temp/MAT_G.csv");
        file << input_img_array[1];
    }
    if(c == BLUE) {
        file.open("./temp/MAT_B.csv");
        file << input_img_array[0];
    }

    return true;
}

bool IPP_draw(version v,IPP_DRAW){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;



    imwrite(output_path,output_img);
    return true;
}

bool IPP_gray(version v){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    cvtColor(input_img,output_img,CV_RGB2GRAY);

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
                 blue, dims, &histSize[0], &ranges[0]);
    //G
    calcHist(&input_img, 1, &channels[1], Mat(),
                 green, dims, &histSize[1], &ranges[1]);
    //B
    calcHist(&input_img, 1, &channels[2], Mat(),
                 red, dims, &histSize[2], &ranges[2]);

    Mat output_red(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    Mat output_green(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    Mat output_blue(histSize[0], histSize[0], CV_8UC3, Scalar(0, 0, 0));
    double maxValue[3] = { 0, 0, 0 };
    double minValue[3] = { 0, 0, 0 };
    minMaxLoc(blue, &minValue[0], &maxValue[0]);
    minMaxLoc(green, &minValue[1], &maxValue[1]);
    minMaxLoc(red, &minValue[2], &maxValue[2]);

    //纵坐标缩放比例
    double rate_blue = (histSize[0] / maxValue[0]);
    double rate_green = (histSize[0] / maxValue[1]);
    double rate_red = (histSize[0] / maxValue[2]);

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

    //addWeighted(output_red, 0.6, output_green ,0.6, 0.0, output_red);
    //addWeighted(output_red, 1.2, output_blue ,0.6,0.0, output_img);

    imwrite(output_path,output_blue);
    return true;
}

bool IPP_split(version v,IPP_CHANNEL c){
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

bool IPP_threshold(version v,double thresh,IPP_THRESHOLD type){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    threshold(input_img,output_img,thresh,255,type);

    imwrite(output_path,output_img);
    return true;
}

bool IPP_floodfill(version v,int x,int y,int range){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    int b = input_img.at<Vec3b>(x,y)[0];
    int g = input_img.at<Vec3b>(x,y)[1];
    int r = input_img.at<Vec3b>(x,y)[2];
    floodFill(input_img,Point(x,y),Scalar(b,g,r),0,Scalar(range,range,range),Scalar(range,range,range));
    output_img = input_img;
    line(output_img,Point(x,y),Point(x+1,y+1),Scalar(0,255,0),5);

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
    
    double rate = brightness / 100.0;


    for (int i = 0; i < img.rows; ++i)
        for (int j = 0; j < img.cols; ++j)
            if (rate > 0)
                img.at<Vec3b>(i, j) += img.at<Vec3b>(i, j) * rate;
            else
                img.at<Vec3b>(i, j) -= img.at<Vec3b>(i, j) * (-rate);

    imwrite(output_path, img);

    return true;
}

bool IPP_contrast(version v, int contrastrate)
{
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v + 1) + ".jpg";

    Mat img = imread(input_path);
    if (img.empty())
        return false;

    int bgr[3] = { 0, 0, 0 };
    for (int i = 0; i < img.rows; ++i)
        for (int j = 0; j < img.cols; ++j) {
            Vec3b pixel = img.at<Vec3b>(i, j);
            bgr[0] += pixel[0];
            bgr[1] += pixel[1];
            bgr[2] += pixel[2];
        }
    bgr[0] = bgr[0] / (img.rows * img.cols);
    bgr[1] = bgr[1] / (img.rows * img.cols);
    bgr[2] = bgr[2] / (img.rows * img.cols);

    double rate = contrastrate / 50.0;

    for (int i = 0; i < img.rows; ++i)
        for (int j = 0; j < img.cols; ++j) {
            Vec3b mean(bgr[0], bgr[1], bgr[2]);
            img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j) * rate + (1 - rate) * mean;
        }

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












