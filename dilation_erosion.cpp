#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], WINDOW_AUTOSIZE);
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    Mat img2(img.rows, img.cols, CV_8UC1, Scalar(0));
    Mat final_img(img.rows, img.cols, CV_8UC1, Scalar(255));
    cvtColor(img, img1, CV_BGR2GRAY);

    int i, j, x, y, white, black;
    // Binary image
    for(i = 0; i < img1.rows; i++)
        for(j = 0; j < img1.cols; j++)
            if(img1.at<uchar>(i, j) > 127)
                img2.at<uchar>(i, j) = 255;

    namedWindow("Binary", WINDOW_AUTOSIZE);
    imshow("Binary", img1);
    for(i = 1; i < img2.rows-1; i++){
        for(j = 1; j < img2.cols-1; j++){
            white = black = 0;
            for(x = -1; x < 2; x++){
                for(y = -1; y < 2; y++){
                    if(img2.at<uchar>(i + x, j + y) == 255)
                        black++;
                    else
                        white++;
                }
            }
            if(white > black){
                for(x = -1; x < 2; x++){
                    for(y = -1; y < 2; y++){
                        final_img.at<uchar>(i + x, j + y) = 0;
                    }
                }
            }
        }
    }
    for(i = 1; i < img2.rows-1; i++){
        for(j = 1; j < img2.cols-1; j++){
            white = black = 0;
            for(x = -1; x < 2; x++){
                for(y = -1; y < 2; y++){
                    if(img2.at<uchar>(i + x, j + y) == 255)
                        black++;
                    else
                        white++;
                }
            }
            if(black > 0){
                for(x = -1; x < 2; x++){
                    for(y = -1; y < 2; y++){
                        final_img.at<uchar>(i + x, j + y) = 255;
                    }
                }
            }
        }
    }

    namedWindow("Dilate", WINDOW_AUTOSIZE);
    imshow("Dilate", final_img);

    waitKey(0);
    return 0;
}
