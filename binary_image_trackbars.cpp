#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    cvtColor(img, img1, CV_BGR2GRAY);
    Mat final_img(img.rows, img.cols, CV_8UC1, Scalar(0));

    namedWindow("Binary Image", WINDOW_AUTOSIZE);
    int threshold = 127;
    createTrackbar("track1", "Binary Image", &threshold, 255);
    int i, j;
    while(1){
        for(i = 0; i < img1.rows; i++){
            for(j = 0; j < img1.cols; j++){
                if(img1.at<uchar>(i, j) > threshold)
                    final_img.at<uchar>(i, j) = 255;
                else
                    final_img.at<uchar>(i, j) = 0;
            }
        }
        imshow("Binary Image", final_img);
        if(waitKey(10) == 'q')
            break;
    }

    return 0;
}
