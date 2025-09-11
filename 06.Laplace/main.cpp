#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

int main(){
    cv::Mat img = cv::imread("images.png", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Input", cv::WINDOW_NORMAL);
    cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::namedWindow("Laplace", cv::WINDOW_NORMAL);

    cv::Mat output, laplace;

    int dx=1;
    int dy=1;
    int sobelKernelSize=3;
    int scaleFactor=1;
    int deltaValue=1;
    while(1){
        cv::Sobel(img,output,CV_8UC1, dx, dy, sobelKernelSize, scaleFactor, deltaValue);
        cv::Laplacian(img,laplace,-1,1,1,0);

        int c = cv::waitKey(1);

        if((char)c == 'q'){
            cout << "pressed to q" << endl;
            break;
        }
        else if((char)c== 'a'){
            cout << "pressed to a" << endl;
            if(dx&&dy){
                dx=0;
            }
            else
                dx=1;
            
        }
        else if((char)c== 's'){
            cout << "pressed to s" << endl;
            if(dx&&dy){
                dy=0;
            }
            else
                dy=1;
            
        }
        
        else if((char)c== 'd'){
            cout << "pressed to d" << endl;
            sobelKernelSize+=2;
        }
        else if((char)c== 'f'){
            cout << "pressed to f" << endl;
            sobelKernelSize-=2;
        }
        else if((char)c== 'z'){
            cout << "pressed to z" << endl;
            scaleFactor++;
        }
        else if((char)c== 'x'){
            cout << "pressed to x" << endl;
            scaleFactor--;
        }
        else if((char)c== 'c'){
            cout << "pressed to c" << endl;
            deltaValue++;
        }
        else if((char)c== 'v'){
            cout << "pressed to v" << endl;
            deltaValue--;
        }
        cv::imshow("Input", img);
        cv::imshow("Output", output);
        cv::imshow("Laplace", laplace);
    }

    return 0;
}