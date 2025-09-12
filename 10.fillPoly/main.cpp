#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){

    cv::Mat img = cv::Mat::zeros(cv::Size(1000,1000),CV_8UC3);

    vector<cv::Point> point = {cv::Point(100,100),cv::Point(200,100),cv::Point(400,600)};

    // cv::fillPoly(img,point,cv::Scalar(0,0,255));
    // cv::fillConvexPoly(img,point,cv::Scalar(0,0,255));
    cv::polylines(img,point,0,cv::Scalar(0,0,255));

    cv::imshow("img",img);
    cv::waitKey(0);

    return 0;
}