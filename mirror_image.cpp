#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat straight, mirror;
    straight = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    mirror = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    namedWindow("Straight", WINDOW_AUTOSIZE);
    imshow("Straight", straight);

    int i,j;
    for(i = 0; i < mirror.rows; i++){
        for(j = 0; j < mirror.cols; j++){
            mirror.at<Vec3b>(i, j) = straight.at<Vec3b>(i, mirror.cols-j - 1);
        }
    }

    namedWindow("Mirror", WINDOW_AUTOSIZE);
    imshow("Mirror", mirror);

    waitKey(0);
    return 0;
}
