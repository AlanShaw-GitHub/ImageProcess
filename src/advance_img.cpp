//
// Created by 肖振新 on 2017/12/7.
//

#include <advance_img.h>

bool IPP_img_face_detection(version v){
    string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
    string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
    Mat input_img = imread(input_path);
    if(input_img.empty() == true)
        return false;
    Mat output_img;

    String face_cascade_name, eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    String window_name = "Capture - Face detection";
    face_cascade_name = "./data/haarcascade_frontalface_alt.xml";
    eyes_cascade_name = "./data/haarcascade_eye_tree_eyeglasses.xml";
    Mat frame = input_img;;

    if( !face_cascade.load( face_cascade_name ) )
        return false;
    if( !eyes_cascade.load( eyes_cascade_name ) )
        return false;

    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2,
                      faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2,
                                      faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x +
                                      eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }

    output_img = frame;

    imwrite(output_path,output_img);
    return true;
}



/*------------templates--------

string input_path = DEFAULT_PATH + to_string(v) + ".jpg";
string output_path = DEFAULT_PATH + to_string(v+1) + ".jpg";
Mat input_img = imread(input_path);
if(input_img.empty() == true)
return false;
Mat output_img;



imwrite(output_path,output_img);
return true;
*/




