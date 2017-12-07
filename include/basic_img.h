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

bool IPP_cut(version v,int x,int y,int sizex,int sizey);
//cut photo ,create new sub photo(vertical for x)
//图像存在ROI_v.jpg,v为输入版本号

bool IPP_csv(version v,IPP_CHANNEL c);
//读取图像每个点的像素值，c为特定通道(R,G.B),文件存在MAT_c.csv,c为通道值(R,G.B)

bool IPP_draw(version v,IPP_DRAW);
//基本绘图操作

bool IPP_gray(version v);
//转为灰度图

bool IPP_blur(version v,int ksize);
//图像模糊

bool IPP_sobel(version v);
//图像锐化

bool IPP_hist(version v);
//显示直方图，直方图图片存在/temp/hist.jpg

bool IPP_split(version v,IPP_CHANNEL c);
//分离RGB值，可选参数为RED,GREEN,BLUE
//图片存在RED_v.jpg,GREENv.jpg,BLUEv.jpg,v为输入版本号

bool IPP_threshold(version v,double thresh,IPP_THRESHOLD type);
//一些基本的阈值化操作，关于type参数具体见
// https://docs.opencv.org/3.3.1/d7/d1b/group__imgproc__misc.html#gaa9e58d2860d4afa658ef70a9b1115576
//各个type类型简介
//THRESH_BINARY 大于thresh的像素点均变为255，小于的归零
//THRESH_BINARY_INV 与上述的相反，小于thresh的变为255，大于的归零
//THRESH_TRUNC 截断操作，大于thresh的点都变为thresh，小于的不变
//THRESH_TOZERO 大于thresh的像素点保持不变，小于的直接归零
//THRESH_TOZERO_INV 与上述相反，大于thresh的归零，小于的不变

bool IPP_floodfill(version v,int x,int y,int range);
//漫水填充算法，种子点为（x，y），变为的颜色为该点的颜色,range为-range<(x,y)点的RGB值<range

#endif //IPP_ZOOM_H


















