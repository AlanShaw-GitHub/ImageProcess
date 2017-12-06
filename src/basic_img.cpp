//
// Created by 肖振新 on 2017/12/6.
//

#include <basic_img.h>

bool IPPresize(version v,double fx, double fy){
    string input_path = "./temp/" + to_string(v) + ".jpg";
    string output_path = "./temp/" + to_string(v+1) + ".jpg";
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

bool IPProtate(version v,double degree){
    string input_path = "./temp/" + to_string(v) + ".jpg";
    string output_path = "./temp/" + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    int maxlength = max(input_img.cols, input_img.rows);
    Point2f pt(maxlength/2.,maxlength/2.);
    Mat r = getRotationMatrix2D(pt,degree,1.0);
    warpAffine(input_img,output_img,r,Size(maxlength,maxlength));

    imwrite(output_path,output_img);
}