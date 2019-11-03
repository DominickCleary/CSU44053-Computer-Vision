// Introductory Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>

using namespace cv;
using std::string;

int main()
{
	string filename = "StayingInLane_CINEPAK.avi";
	VideoCapture capture(filename);
	Mat frame;

	if (!capture.isOpened()) {
		throw "Error when reading video";
	}

	int current_threshold = 128;
	int max_threshold = 255;

	namedWindow("Binary Transformation", 1);

	for (; ; ) {
		capture >> frame;
		if (frame.empty()) {
			break;
		}

		Mat otsu_binary_image, gray_frame;
		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
		threshold(gray_frame, otsu_binary_image, current_threshold, max_threshold, THRESH_BINARY | THRESH_OTSU);
		Mat otsu_binary_image_display;
		cvtColor(otsu_binary_image, otsu_binary_image_display, COLOR_GRAY2BGR);
		imshow("Introductory Lab", frame);
		imshow("Binary Transformation", otsu_binary_image_display);
		waitKey(20);
	}
	waitKey(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
