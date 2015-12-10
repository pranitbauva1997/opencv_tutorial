#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat final_img(img.rows, img.cols, CV_8UC1, Scalar(255));
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    cvtColor(img, img1, CV_BGR2GRAY);

    int threshold = 50;
    int i, j, x, y;
    int max, min;
    namedWindow("Edge Detection", WINDOW_AUTOSIZE);
    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", img1);
    createTrackbar("Threshold", "Edge Detection", &threshold, 255);
    while(1){
        for(i = 1; i < img.rows - 1; i++){
            for(j = 1; j < img.cols - 1; j++){
                for(x = i - 1; x < i + 1; x++){
                    for(y = j -1; y < j + 1; y++){
                        max = img1.at<uchar>(i - 1, j - 1);
                        if(img1.at<uchar>(x, y) > max)
                            max = img1.at<uchar>(x, y);
                        min = img1.at<uchar>(i - 1, j - 1);
                        if(img1.at<uchar>(x, y) < min)
                            min = img1.at<uchar>(x, y);
                    }
                }
                if( (max - min) > threshold )
                    final_img.at<uchar>(i, j) = 0;
            }
        }
        imshow("Edge Detection", final_img);
        if(waitKey(20) == 'q')
            break;
        for(i = 0; i < img.rows; i++)
            for(j = 0; j < img.cols; j++)
                final_img.at<uchar>(i, j) = 255;
    }

    return 0;
}
