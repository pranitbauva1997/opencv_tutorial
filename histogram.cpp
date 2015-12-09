#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    cvtColor(img, img1, CV_BGR2GRAY);
    Mat histo(500, 500, CV_8UC1, Scalar(255));

    long intensity[256];
    int i, j;


    for(i = 0; i < 256; i++)
        intensity[i] = 0;

    for(i = 0; i < img1.rows; i++)
        for(j = 0; j < img1.cols; j++)
            intensity[img1.at<uchar>(i, j)]++;

    for(i = 0; i < 256; i++)
        intensity[i] /= 100;

    for(i = 0; i < 256; i++)
        histo.at<uchar>(400-intensity[i], i) = 0;

    namedWindow("Histogram", WINDOW_AUTOSIZE);
    imshow("Histogram", histo);

    waitKey(0);
    return 0;
}
