#include <opencv2/opencv.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;


int main(int argc, char*argv[])
{

   if(argc < 2) {

      cout << "无图片 >" << endl ;

      return 0;
  }

 
	string image_name(argv[1]);

	Mat image = imread(image_name,IMREAD_GRAYSCALE);

	int histsize = 256;

	float range[] = { 0,255 };

	const float*histRanges = { range };
	
	Mat hist;

	Mat result;

	calcHist(&image, 1, 0, Mat(), hist, 1, &histsize, &histRanges, true, false);/*
用来计算图像直方图*/
	int hist_h = 512;

	int hist_w = 512;

	int bin_w = hist_w / histsize;

	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(176, 48, 96));/*创建一个长宽为wh的黑色背景*/

	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());/*将直方图归一化到范围[0, histImage.rows]*/

for (int i = 1; i < histsize; i++)/*画直方图*/
	{
		
	line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(hist.at<float>(i - 1))),

	Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 192, 203), 2, CV_AA);
		
	}

	imshow("output", histImage);

	namedWindow("Display Window",WINDOW_NORMAL);

	imshow("Display Window",image);
	
	
	result = image.clone();   /*创造一个和原图一样大小的矩阵*/

	threshold(image, result, 50, 220,CV_THRESH_BINARY);

	namedWindow("二值化图像",WINDOW_NORMAL);

	imshow("二值化图像", result);

	waitKey(0);

	return 0;

}
