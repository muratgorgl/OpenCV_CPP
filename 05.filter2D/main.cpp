#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){
    cv::Mat input = cv::imread("image.jpeg");
    cv::Mat_<float>kernel(3,3);

    cv::namedWindow("Input",cv::WINDOW_NORMAL);
    cv::namedWindow("Output",cv::WINDOW_NORMAL);
    cv::namedWindow("Kernel",cv::WINDOW_NORMAL);

    // input << 1,8,9,4,5,6,3,2,1;
    // Gaussian Blur
    kernel << 0.0625,0.125,0.0625,
                0.125,0.25,0.125,
                0.0625,0.125,0.0625;

    cv::Mat input2, kernel2, output, output2;
    
    cv::filter2D(input,output,-1, kernel, cv::Point(-1,-1));

    input.convertTo(input2, CV_8UC1);
    kernel.convertTo(kernel2, CV_8UC1);
    output.convertTo(output2, CV_8UC1);

    cv::imshow("Input", input2);
    cv::imshow("Output", output2);
    cv::imshow("Kernel", kernel2);

    // cout << "Input:\n" << input << endl;
    // cout << "Kernel:\n" << kernel << endl;
    // cout << "Output:\n" << output << endl;

    cv::waitKey(0);

    return 0;
}