#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_webcam_clicked()
{
    cap.open(0);

    if(!cap.isOpened())  // Check if we succeeded
    {
        cout << "camera is not open" << endl;
    }
    else
    {
        cout << "camera is open" << endl;

        connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        timer->start(20);
    }
}

void MainWindow::on_pushButton_close_webcam_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
    cap.release();

    Mat image = Mat::zeros(frame.size(),CV_8UC3);

    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(qt_image));

    ui->label->resize(ui->label->pixmap()->size());

    cout << "camera is closed" << endl;
}

void MainWindow::on_pushButton_display_frame_clicked()
{
    ui->label_2->setText("Ciekawe czy działa?");

    VideoCapture Frame(0);
        while(true)
        {
            Mat cameraframe;
           Frame.read(cameraframe);


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

            }
            // Detect face
            std::vector<Rect> face;
            face_cascade.detectMultiScale(cameraframe, face, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30,30));
            // Draw circles on the detected face
            for( int i = 0; i < face.size(); i++ )
           {
                Point center( face[i].x + face[i].width*0.5, face[i].y + face[i].height*0.5 );
                ellipse( cameraframe, center, Size( face[i].width*0.5, face[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

            // Detect eyes
            Mat faceROI = cameraframe( face[i] );
            std::vector<Rect> eye;
            eye_cascade.detectMultiScale(faceROI, eye, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30,30));
            // Draw circules on detected eye
            for(int j = 0; j < eye.size(); j++ )
            {
                Point center( face[i].x + eye[j].x + eye[j].width*0.5, face[i].y + eye[j].y + eye[j].height*0.5 );
                int radius = cvRound( (eye[j].width + eye[j].height)*0.25 );
                circle( cameraframe, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );

            }
          }

            imshow("Detected Face", cameraframe);
            waitKey();




            QString file_name = QFileDialog::getSaveFileName(this, tr("Save File"),
                    "D://",
                    tr("Images (*.png *.jpg)"));
            //*imageObject = image.toImage();
            //Mat::frame -> M.save(&file_name, "PNG");
            VideoCapture Frame(0) -> save(file_name);



        }
}

void MainWindow::on_pushButton_save_image_clicked()
{


    VideoCapture Frame2(0);
    Frame2.read(cameraframe2);
   // Mat frame;
    //cap >> frame;

    QString file_name = QFileDialog::getSaveFileName(this, tr("Save File"),
            "D://",
            tr("Images (*.png *.jpg)"));
    //*imageObject = image.toImage();
    //Mat::frame -> M.save(&file_name, "PNG");
    cameraframe -> save(file_name);




}

void MainWindow::update_window()
{
    cap >> frame;

    cvtColor(frame, frame, CV_BGR2RGB);

    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(qt_image));

    ui->label->resize(ui->label->pixmap()->size());
}
