//
// Created by 肖振新 on 2017/12/6.
//

#ifndef IPP_ZOOM_H
#define IPP_ZOOM_H
#include <IPP_USAGE.h>

bool IPPresize(version v,double fx, double fy);
//resize photo,zoom in or zoom out(inreversible)
bool IPProtate(version v,double degree);
//rotate photo
bool IPPblur(version v,int ksize);
//图像模糊
bool IPPsobel(version v);
//图像锐化
bool IPPhist(version v);
//显示直方图，直方图图片存在/temp/hist.jpg


#endif //IPP_ZOOM_H
