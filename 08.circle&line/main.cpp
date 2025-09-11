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
    int thickness=4;
    int radius=3;
    int shift=1;

    cv::createTrackbar("Point 1","Rect", &point1, 800);
    cv::createTrackbar("Point 2","Rect", &point2, 800);
    cv::createTrackbar("Thickness","Rect", &thickness, 25);
    cv::createTrackbar("Radius","Rect", &radius, 100);
    cv::createTrackbar("Shift","Rect", &shift, 10);
    while(1){
        
        
        // cv::line(img,cv::Point(point1,point2),cv::Point(500,500),cv::Scalar(0,255,255),thickness,cv::LINE_AA);
        
        cv::circle(img,cv::Point(point1,point2),radius, cv::Scalar(0,255,255),thickness,cv::LINE_AA,shift);

        cv::arrowedLine(img,cv::Point(point1,point2),cv::Point(150,150),cv::Scalar(0,255,255),thickness, cv::LINE_AA,shift);
        
        // cv::rectangle(img,cv::Point(point1,point1),cv::Point(point2,point2),cv::Scalar(0,255,0),3,cv::LINE_4);
 
        cv::imshow("Rect", img);
        cv::waitKey(1);
        img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);
    }
 

    return 0;
}