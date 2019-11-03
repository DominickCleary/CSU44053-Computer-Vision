// Introductory Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>

//using namespace std;
using namespace cv;
using std::string;

int main()
{
	std::vector<String> fn;
	glob("S:\Documents\GitHub\CSU44053-Computer-Vision\Assignment 1\Images\*.png", fn, false);

	std::vector<Mat> images;
	size_t count = fn.size();
	for (size_t i = 0; i < count; i++) {
		images.push_back(imread(fn[i]));
	}
}