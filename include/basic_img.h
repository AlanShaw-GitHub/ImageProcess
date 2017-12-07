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


// 改变图片的亮度，brightness表示增加的亮度(可正可负)
bool IPP_brightness(version v, uchar brightness);
// 改变图片的对比度，contrast_rate表示对比度的相对比率值(>0)
bool IPP_contrast(version v, double contrast_rate);



#endif //IPP_ZOOM_H
