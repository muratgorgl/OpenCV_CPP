#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){

    cv::Mat img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);

    vector<vector<cv::Point>> contour ={
        {cv::Point(100,100),cv::Point(200,200), cv::Point(100,200),cv::Point(200,100)},
        {cv::Point(400,400),cv::Point(400,500)},
        {cv::Point(600,600),cv::Point(600,800)}
    };  

    for(int i=0;i<(int)contour.size();i++)
        cv::drawContours(img,contour,i,cv::Scalar(0,255,255),5);

    cv::imshow("img",img);
    cv::waitKey(0);

    return 0;
}