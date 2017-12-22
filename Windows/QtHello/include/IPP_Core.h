//
// Created by 肖振新 on 2017/12/6.
//

#ifndef IPP_CORE_H
#define IPP_CORE_H

#include <E:\opencv\opencv\build\include\opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using  namespace cv;

#define  DEFAULT_PATH "D:/temp/"
#define PI 3.1415926
typedef int version;
enum IPP_TYPE{
    COMPRESS,
    REBUILD
};
enum IPP_CHANNEL{
    RED,
    GREEN,
    BLUE
};
enum IPP_DRAW{
    ELLIPSE,
    CIRCLE,
    LINE
};
enum IPP_THRESHOLD{
    THRESH_BINARY     = 0,
    //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{maxval}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
    THRESH_BINARY_INV = 1,
    //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{maxval}}{otherwise}\f]
    THRESH_TRUNC      = 2,
    //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{threshold}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]
    THRESH_TOZERO     = 3,
    //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{src}(x,y)}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
    THRESH_TOZERO_INV = 4,
    //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]

};

#endif //IPP_CORE_H
