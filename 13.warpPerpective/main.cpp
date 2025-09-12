#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

vector<Point2f> points;

void mouseHandler(int event, int x, int y, int flags, void* param){
    if(event == EVENT_LBUTTONDOWN){
        points.push_back(Point2f(x,y));
        cout << "Point selected: " << x << ", " << y << endl;
        circle(*(Mat*)param, Point(x,y), 5, Scalar(0,0,255), FILLED);
        imshow("Input", *(Mat*)param);
    }
}

int main(){
    Mat img = imread("image.jpg");
    Mat output;
    if(img.empty()){
        cout << "Image not found!" << endl;
        return -1;
    }

    namedWindow("Input", WINDOW_NORMAL);
    namedWindow("Output",0);

    cv::Point2f src[]={
        cv::Point(676,31),
        cv::Point(1175,239),
        cv::Point(350,800),
        cv::Point(859,1003)
    };

    cv::Point2f dst[]={
        cv::Point(0,0),
        cv::Point(500,0),
        cv::Point(0,800),
        cv::Point(500,800)
    };

    setMouseCallback("Input", mouseHandler, &img);

    Mat matrix = cv::getPerspectiveTransform(src,dst);
    cv::warpPerspective(img,output,matrix,cv::Size(500,800));

    imshow("Input", img);
    imshow("Output", output);
    waitKey(0);

    
    cout << "\nSelected points:" << endl;
    for(size_t i=0; i<points.size(); i++){
        cout << points[i] << endl;
    } 

    return 0;
}
