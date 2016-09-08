//============================================================================
// Name        : GetP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#define TEST1

using namespace cv;

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

#ifdef TEST1
	//test CvCapture
	CvCapture* capture;
	capture = cvCreateCameraCapture(CV_CAP_ANY);
	if(NULL == capture)
	{
		fprintf(stdout, "Open camera failed!\n");
		return false;
	}
	fprintf(stdout, "cvSetCaptureProperty value is  %d.\n", cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 1280));
	fprintf(stdout, "cvSetCaptureProperty value is  %d.\n", cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 720));
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 1280);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 720);

	IplImage* frame1;
	frame1 = cvQueryFrame(capture);
	if(!frame1)
	{
		//return failure of get photo to robot
		fprintf(stdout, "Get photo failed!\n");
		return 0;
	}
	else
	{
		fprintf(stdout, "Get photo successfully!\n");
		cvSaveImage("//home//jacky//workspace//GetP/photo//0_o.jpg",frame1);
	}
#else
	//test VideoCapture
	IplImage  outimage;
	Mat frame;
	IplImage *outvedio = NULL;
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		fprintf(stderr, "Can not open camera.\n");
		return 0;
	}
	cap >> frame;
	outimage = frame;
	outvedio = &outimage;
	cvSaveImage("//home//jacky//workspace//GetP/photo//0_a.jpg",outvedio);
#endif
	return 0;
}
