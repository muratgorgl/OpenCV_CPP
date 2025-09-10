#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){

    cv::Mat bilateralImg, gaussianImg, medianImg;

    cv::Mat img = cv::imread("image.jpeg");

    cv::bilateralFilter(img, bilateralImg, 15, 95, 45);
    cv::GaussianBlur(img, gaussianImg, cv::Size(15,15), 0);
    cv::medianBlur(img, medianImg, 15);

    cv::imshow("Original", img);
    cv::imshow("Bilateral", bilateralImg);
    cv::imshow("Gaussian", gaussianImg);
    cv::imshow("Median", medianImg);

    cv::waitKey(0);

    return 0;
}