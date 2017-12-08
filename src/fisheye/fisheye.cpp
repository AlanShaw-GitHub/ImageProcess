//
// Created by 肖振新 on 2017/12/8.
//

#include <video/fisheye.h>

/*
* Holographic_Projection.cpp
*
* Author:
* Alan Shaw <452406919[at]qq[dot]com>
*
* Date:
* 2017.10.25
*
* Platform:
* OpenCV 3.3.0
*
* This program helps you to transfer your origin video to "fisheye figure",which  can be holographic projected.
* Useful args you may need:
*	 #define image_size 500//the output video's size(500*500)
*	 VideoCapture video("Taylor.mp4");//Read video from(default Taylor.mp4)
*	 VideoWriter outvideo("out.avi",VideoWriter::fourcc('M','J','P','G'),30,Size(image_size,image_size));//output video
*	 int vertical_concat = 300;//pure black space added above the image
*	 int horizontal_concat = 600;//pure black space added horizontally
*	 Note that the vertical_concat and int horizontal_concat are used to compensate the distortion!
*	 You need to decide the value depends on your source video!
*/


bool IPP_fisheye_video(version v,int image_size,int space){
    string video_path = DEFAULT_PATH + to_string(v) + ".mp4";
    string video_path_out = DEFAULT_PATH + to_string(v+1) + ".mp4";
    VideoCapture video(video_path);//Read video
    VideoWriter outvideo(video_path_out, VideoWriter::fourcc('M','J','P','G'),
                         30, Size(image_size, image_size));//output video
    Mat frame, out;

    while (video.read(frame)) {
        vconcat(Mat::zeros(space, frame.cols, CV_8UC3), frame,frame);
        processRGBimage(frame, out,image_size);
        outvideo.write(out);
    }
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
