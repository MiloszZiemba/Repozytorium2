#include "mainwindow.h" // NIE USUWAC!!!!
#include <QApplication> // NIE USUWAC!!!!
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{/*
    Mat image;
    image = imread("C:\\Users\\locky\\OneDrive\\Pulpit\\opencv-face-haarcascade-input.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow("FaceDetection",1);
    imshow("FaceDetection",image);

    //Load Face and Eyes Cascade(.xml file)
    CascadeClassifier face_cascade;
    CascadeClassifier eye_cascade;
    face_cascade.load("D:\\opencv\\release\\install\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");
    eye_cascade.load("D:\\opencv\\release\\install\\etc\\haarcascades\\haarcascade_eye.xml");
            if(face_cascade.empty())
            //if(!face_cascade.load("D:\\opencv\\release\\install\\etc\\haarcascades\\haarcascade_frontalface_alt.xml")
            if(eye_cascade.empty())
                //if(!eye_cascade.load("D:\\opencv\\release\\install\\etc\\haarcascades\\haarcascade_eye.xml")
    {
        cerr<<"ERROR Loading XML file"<<endl;
        return 0;
    }
    // Detect face
    std::vector<Rect> face;
    face_cascade.detectMultiScale(image, face, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30,30));
    // Draw circles on the detected face
    for( int i = 0; i < face.size(); i++ )
   {
        Point center( face[i].x + face[i].width*0.5, face[i].y + face[i].height*0.5 );
        ellipse( image, center, Size( face[i].width*0.5, face[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    // Detect eyes
    Mat faceROI = image( face[i] );
    std::vector<Rect> eye;
    eye_cascade.detectMultiScale(faceROI, eye, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30,30));
    // Draw circules on detected eye
    for(int j = 0; j < eye.size(); j++ )
    {
        Point center( face[i].x + eye[j].x + eye[j].width*0.5, face[i].y + eye[j].y + eye[j].height*0.5 );
        int radius = cvRound( (eye[j].width + eye[j].height)*0.25 );
        circle( image, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );

    }
  }

    imshow("Detected Face", image);
    waitKey(0);


    return 0;
}*/


    QApplication a(argc, argv); // NIE USUWAC!!!!
    MainWindow w; // NIE USUWAC!!!!
    w.show(); // NIE USUWAC!!!!



    return a.exec(); // NIE USUWAC!!!!
}
