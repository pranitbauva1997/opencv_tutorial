#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image(200, 400, CV_8UC3, Scalar(0,255,0));
    imshow("Display Window", image);

    waitKey(0);
    return 0;
}
