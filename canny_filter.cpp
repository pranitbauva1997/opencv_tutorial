#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

void CannyThreshold(int, void*){
    // Reduce noise with a kernel 3x3
    blur(src_gray, detected_edges, Size(3, 3));

    // Canny detector
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

    // Using Canny's out as a mask, we display our result
    dst = Scalar::all(0);

    src.copyTo(dst, detected_edges);
    imshow("Edge Map", dst);
}

int main(int argc, char **argv){
    // Load an image
    src = imread(argv[1]);

    // Create a matrix of the same type and size as src (for dst)
    dst.create(src.size(), src.type());

    // Convert the image to grayscale
    cvtColor(src, src_gray, CV_BGR2GRAY);

    // Create a window
    namedWindow("Edge Map", CV_WINDOW_AUTOSIZE);

    // Create a Trackbar for user to enter threshold
    createTrackbar("Min Threshold:", "Edge Map", &lowThreshold, max_lowThreshold, CannyThreshold);

    // Show the image
    CannyThreshold(0, 0);

    waitKey(0);
    return 0;
}
