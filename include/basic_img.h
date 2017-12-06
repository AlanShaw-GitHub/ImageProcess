//
// Created by 肖振新 on 2017/12/6.
//

#ifndef IPP_ZOOM_H
#define IPP_ZOOM_H
#include <IPP_USAGE.h>

bool IPP_resize(version v,double fx, double fy);
//resize photo,zoom in or zoom out(inreversible)
bool IPP_rotate(version v,double degree);
//rotate photo
bool IPP_blur(version v,int ksize);
//图像模糊
bool IPP_sobel(version v);
//图像锐化
bool IPP_hist(version v);
//显示直方图，直方图图片存在/temp/hist.jpg
bool IPP_split(version v,channel c);
//分离RGB值，可选参数为RED,GREEN,BLUE


#endif //IPP_ZOOM_H
