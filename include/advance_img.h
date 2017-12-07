//
// Created by 肖振新 on 2017/12/7.
//

#ifndef IPP_ADVANCE_IMG_H
#define IPP_ADVANCE_IMG_H

#include <IPP_Core.h>

bool IPP_img_face_detection(version v);
//人脸和人眼检测

bool IPP_addweight(version v1,version v2,double weightv1,double weightv2);
//添加图层（图片混合操作）,weightv1,weightv2为权重，
//建议weightv1+weightv2=1.0,图片将被存在addweight_v1_v2.jpg,如addweight_1_2.jpg
//如果两张图片大小不同，将会将v2裁剪到与v1一样大，然后混合


#endif //IPP_ADVANCE_IMG_H
