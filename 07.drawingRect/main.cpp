#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){

    cv::namedWindow("Rect", cv::WINDOW_NORMAL);
    cv::Mat img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);

    int point1=100;
    int point2=200;

    cv::createTrackbar("Point 1","Rect", &point1, 500);
    cv::createTrackbar("Point 2","Rect", &point2, 500);


    while(1){
    cv::rectangle(img,cv::Point(point1,point1),cv::Point(point2,point2),cv::Scalar(0,255,0),3,cv::LINE_4);

    cv::imshow("Rect", img);
    cv::waitKey(1);
    img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);
    }
 

    return 0;
}