#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

using namespace std;

int main(){
    cv::Mat img = cv::imread("lena.jpeg");
    cv::imshow("Window", img);

    cv::waitKey(0);

    return 0;
}