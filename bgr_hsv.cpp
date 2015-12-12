#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img_hsv(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
    cvtColor(img, img_hsv, CV_BGR2HSV);

    namedWindow("BGR", WINDOW_AUTOSIZE);
    namedWindow("HSV", WINDOW_AUTOSIZE);
    imshow("BGR", img);
    imshow("HSV", img_hsv);
    waitKey(0);
    return 0;
}
