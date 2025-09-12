#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

using namespace std;

int main(){
    cv::Mat img = cv::imread("lena.jpeg");
    cv::Mat output;

    cv::resize(img,output,cv::Size(600,600),0,0);



    cv::imshow("Window", img);
    cv::imshow("Output", output);

    cv::waitKey(0);

    return 0;
}