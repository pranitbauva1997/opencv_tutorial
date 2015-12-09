#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img1;
    img1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img2(img1.rows, img1.cols, CV_8UC1, Scalar(0));
    Mat img3(img1.rows, img1.cols, CV_8UC1, Scalar(0));

    int i, j;
    for(i = 0; i < img1.rows; i++){
        for(j = 0; j < img1.cols; j++){
            img2.at<uchar>(i, j) = (img1.at<Vec3b>(i, j)[0] + img1.at<Vec3b>(i, j)[1] + img1.at<Vec3b>(i, j)[2]) / 3;
        }
    }
    for(i = 0; i < img1.rows; i++){
        for(j = 0; j < img1.cols; j++){
            img3.at<uchar>(i, j) = 0.11*img1.at<Vec3b>(i, j)[0] + 0.59*img1.at<Vec3b>(i, j)[1] + 0.3*img1.at<Vec3b>(i, j)[2];
        }
    }

    namedWindow("Normal", WINDOW_AUTOSIZE);
    imshow("Normal", img1);
    namedWindow("Average", WINDOW_AUTOSIZE);
    imshow("Average", img2);
    namedWindow("Weighted Average", WINDOW_AUTOSIZE);
    imshow("Weighted Average", img3);

    waitKey(0);
    return 0;
}
