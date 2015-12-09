#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    Mat img_binary(img.rows, img.cols, CV_8UC1, Scalar(0));
    cvtColor(img, img1, CV_BGR2GRAY);

    int i, j;
    for(i = 0; i < img.rows; i++)
        for(j = 0; j < img.cols; j++)
            if(img1.at<uchar>(i, j) > 127)
                img_binary.at<uchar>(i, j) = 255;

    namedWindow("Normal", WINDOW_AUTOSIZE);
    imshow("Normal", img);
    namedWindow("Binary", WINDOW_AUTOSIZE);
    imshow("Binary", img_binary);

    waitKey(0);
    return 0;
}
