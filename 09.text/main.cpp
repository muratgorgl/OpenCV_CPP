#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){

    cv::Mat img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);

    cv::putText(img,"Hello",cv::Point(100,100),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(255,0,0),2,cv::LINE_AA,false);

    int bL=0;
    cv::getTextSize("Hello", cv::FONT_HERSHEY_SIMPLEX,1,2,&bL);

    cv::imshow("img",img);
    cv::waitKey(0);

    return 0;
}