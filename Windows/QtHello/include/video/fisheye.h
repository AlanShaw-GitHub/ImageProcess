//
// Created by 肖振新 on 2017/12/8.
//

#ifndef IPP_FISHEYE_H
#define IPP_FISHEYE_H

#include "include/IPP_Core.h"

bool IPP_fisheye_video(version v,int image_size = 500,int space = 150);
//将会更改在temp/v.mp4的文件并写到temp/v+1.mp4
//image_size为图片半径，space为中间留白半径

void processRGBimage(Mat & source, Mat & out,int image_size);
bool cartesian_to_polar(cv::Mat& mat_c, cv::Mat& mat_p, int img_d);
uchar interpolate_bilinear(cv::Mat& mat_src, double ri, int rf, int rc, double ti, int tf, int tc);
//function support for IPP_fisheye()

#endif //IPP_FISHEYE_H
