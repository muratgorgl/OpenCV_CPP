#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){
    cv::Mat img= cv::imread("images.png");

    cv::Mat erodeMat, dilateMat;
    cv::Mat elementKernel= cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5),cv::Point(-1,-1));

    cv::erode(img,erodeMat,elementKernel,cv::Point(-1,-1),1);
    cv::dilate(img,dilateMat,elementKernel,cv::Point(-1,-1),1);

    cv::imshow("Original", img);
    cv::imshow("Erode", erodeMat);
    cv::imshow("Dilate", dilateMat);

    cv::waitKey(0);

    return 0;
}