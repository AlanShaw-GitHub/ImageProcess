//
// Created by 肖振新 on 2017/12/7.
//

#include <advance_img.h>

bool IPP_img_face_detection(version v){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    String face_cascade_name, eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    String window_name = "Capture - Face detection";
    face_cascade_name = "./data/haarcascade_frontalface_alt.xml";
    eyes_cascade_name = "./data/haarcascade_eye_tree_eyeglasses.xml";
    Mat frame = input_img;;

    if( !face_cascade.load( face_cascade_name ) )
        return false;
    if( !eyes_cascade.load( eyes_cascade_name ) )
        return false;

    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2,
                      faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2,
                                      faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x +
                                      eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }

    output_img = frame;

    imwrite(output_path,output_img);
    return true;
}

bool IPP_addweight(version v1,version v2,double weightv1,double weightv2){
    string input_path1 = DEFAULT_PATH + to_string(v1) + ".jpg";
    string input_path2 = DEFAULT_PATH + to_string(v2) + ".jpg";
    string output_path = DEFAULT_PATH + string("addweight_") + to_string(v1) +
                         string("_") + to_string(v2) + ".jpg";
    Mat input_img1 = imread(input_path1);
    Mat input_img2 = imread(input_path2);
    if(input_img1.empty() || input_img2.empty())
        return false;
    Mat output_img;
    resize(input_img2,input_img2,Size(input_img1.cols,input_img1.rows));
    addWeighted(input_img1,weightv1,input_img2,weightv2,0.0,output_img);

    imwrite(output_path,output_img);
    return true;
}

bool IPP_fisheye(version v,int image_size,int space){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    vconcat(Mat::zeros(space, input_img.cols, CV_8UC3), input_img,input_img);

    processRGBimage(input_img,output_img,image_size);

    imwrite(output_path,output_img);
    return true;
}


void processRGBimage(Mat & source, Mat & out,int image_size) {
    Mat out1, out2, out3;
    vector<Mat> vec;
    split(source, vec);
    cartesian_to_polar(vec[0], out1, image_size);
    cartesian_to_polar(vec[1], out2, image_size);
    cartesian_to_polar(vec[2], out3, image_size);
    vec[0] = out1;
    vec[1] = out2;
    vec[2] = out3;
    merge(vec, out);
}

bool cartesian_to_polar(cv::Mat& mat_c, cv::Mat& mat_p, int img_d)
{
    mat_p = cv::Mat::zeros(img_d, img_d, CV_8UC1);

    int line_len = mat_c.rows;
    int line_num = mat_c.cols;

    double delta_r = (2.0*line_len) / (img_d - 1); //radius factor
    double delta_t = 2.0 * PI / line_num; //angle factor

    double center_x = (img_d - 1) / 2.0;
    double center_y = (img_d - 1) / 2.0;

    for (int i = 0; i < img_d; i++)
    {
        for (int j = 0; j < img_d; j++)
        {
            double rx = j - center_x; //transfer to polar
            double ry = center_y - i;

            double r = std::sqrt(rx*rx + ry*ry);

            if (r <= (img_d - 1) / 2.0)
            {
                double ri = r * delta_r;
                int rf = (int)std::floor(ri);
                int rc = (int)std::ceil(ri);

                if (rf < 0)
                {
                    rf = 0;
                }
                if (rc >(line_len - 1))
                {
                    rc = line_len - 1;
                }

                double t = std::atan2(ry, rx);

                if (t < 0)
                {
                    t = t + 2.0 * PI;
                }

                double ti = t / delta_t;
                int tf = (int)std::floor(ti);
                int tc = (int)std::ceil(ti);

                if (tf < 0)
                {
                    tf = 0;
                }
                if (tc >(line_num - 1))
                {
                    tc = line_num - 1;
                }

                mat_p.ptr<uchar>(i)[j] = interpolate_bilinear(mat_c, ri, rf, rc, ti, tf, tc);
            }
        }
    }

    return true;
}

uchar interpolate_bilinear(cv::Mat& mat_src, double ri, int rf, int rc, double ti, int tf, int tc)
{
    double inter_value = 0.0;

    if (rf == rc && tc == tf)
    {
        inter_value = mat_src.ptr<uchar>(rc)[tc];
    }
    else if (rf == rc)
    {
        inter_value = (ti - tf) * mat_src.ptr<uchar>(rf)[tc] +
                (tc - ti) * mat_src.ptr<uchar>(rf)[tf];
    }
    else if (tf == tc)
    {
        inter_value = (ri - rf) * mat_src.ptr<uchar>(rc)[tf] +
                (rc - ri) * mat_src.ptr<uchar>(rf)[tf];
    }
    else
    {
        double inter_r1 = (ti - tf) * mat_src.ptr<uchar>(rf)[tc] +
                (tc - ti) * mat_src.ptr<uchar>(rf)[tf];
        double inter_r2 = (ti - tf) * mat_src.ptr<uchar>(rc)[tc] +
                (tc - ti) * mat_src.ptr<uchar>(rc)[tf];

        inter_value = (ri - rf) * inter_r2 + (rc - ri) * inter_r1;
    }

    return (uchar)inter_value;
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