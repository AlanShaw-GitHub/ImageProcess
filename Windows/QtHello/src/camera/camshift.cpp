//
// Created by 肖振新 on 2017/12/7.
//

#include "include/camera/camshift.h"

/*
This is a program that shows mean-shift based tracking
You select a color objects such as your face and it tracks it.
This reads from video camera

Hot keys:
ESC - quit the program

To initialize tracking, select the object with mouse
*/

Mat image;

bool selectObject = false;
int trackObject = 0;
Point origin;
Rect selection;
int vmin = 10, vmax = 256, smin = 30;

// User draws box around object to track. This triggers CAMShift to start tracking
static void onMouse( int event, int x, int y, int, void* )
{
    if( selectObject )
    {
        selection.x = MIN(x, origin.x);
        selection.y = MIN(y, origin.y);
        selection.width = std::abs(x - origin.x);
        selection.height = std::abs(y - origin.y);

        selection &= Rect(0, 0, image.cols, image.rows);
    }

    switch( event )
    {
        case EVENT_LBUTTONDOWN:
            origin = Point(x,y);
            selection = Rect(x,y,0,0);
            selectObject = true;
            break;
        case EVENT_LBUTTONUP:
            selectObject = false;
            if( selection.width > 0 && selection.height > 0 )
                trackObject = -1;   // Set up CAMShift properties in main() loop
            break;
    }
}


bool IPP_camshift(){
    VideoCapture cap;
    Rect trackWindow;
    int hsize = 16;
    float hranges[] = {0,180};
    const float* phranges = hranges;
    cap.open(0);

    namedWindow( "Histogram", 0 );
    namedWindow( "CamShift Demo", 0 );
    setMouseCallback( "CamShift Demo", onMouse, 0 );
    createTrackbar( "Vmin", "CamShift Demo", &vmin, 256, 0 );
    createTrackbar( "Vmax", "CamShift Demo", &vmax, 256, 0 );
    createTrackbar( "Smin", "CamShift Demo", &smin, 256, 0 );

    Mat frame, hsv, hue, mask, hist, backproj;
    bool paused = false;

    for(;;)
    {
        if( !paused )
        {
            cap >> frame;
            if( frame.empty() )
                break;
        }

        frame.copyTo(image);

        if( !paused )
        {
            cvtColor(image, hsv, COLOR_BGR2HSV);

            if( trackObject )
            {
                int _vmin = vmin, _vmax = vmax;

                inRange(hsv, Scalar(0, smin, MIN(_vmin,_vmax)),
                        Scalar(180, 256, MAX(_vmin, _vmax)), mask);
                int ch[] = {0, 0};
                hue.create(hsv.size(), hsv.depth());
                mixChannels(&hsv, 1, &hue, 1, ch, 1);

                if( trackObject < 0 )
                {
                    // Object has been selected by user, set up CAMShift search properties once
                    Mat roi(hue, selection), maskroi(mask, selection);
                    calcHist(&roi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
                    normalize(hist, hist, 0, 255, NORM_MINMAX);

                    trackWindow = selection;
                    trackObject = 1; // Don't set up again, unless user selects new ROI


                    Mat buf(1, hsize, CV_8UC3);
                    for( int i = 0; i < hsize; i++ )
                        buf.at<Vec3b>(i) = Vec3b(saturate_cast<uchar>(i*180./hsize), 255, 255);
                    cvtColor(buf, buf, COLOR_HSV2BGR);

                }

                // Perform CAMShift
                calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
                backproj &= mask;
                RotatedRect trackBox = CamShift(backproj, trackWindow,
                            TermCriteria( TermCriteria::EPS | TermCriteria::COUNT, 10, 1 ));
                if( trackWindow.area() <= 1 )
                {
                        int cols = backproj.cols, rows = backproj.rows, r = (MIN(cols, rows) + 5)/6;
                        trackWindow = Rect(trackWindow.x - r, trackWindow.y - r,
                                           trackWindow.x + r, trackWindow.y + r) &
                                      Rect(0, 0, cols, rows);
                    }


                ellipse( image, trackBox, Scalar(0,0,255), 3, LINE_AA );
            }
        }


        if( selectObject && selection.width > 0 && selection.height > 0 )
        {
            Mat roi(image, selection);
            bitwise_not(roi, roi);
        }

        imshow( "CamShift Demo", image );

        char c = (char)waitKey(10);
        if( c == 27 )
            break;

    }

    return true;
}
