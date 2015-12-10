#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread("bikini.jpg", CV_LOAD_IMAGE_COLOR);
    //Mat final_img(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
    int kernel_size = 3;
    float kernel = (kernel_size*kernel_size);
    float sumb, sumg, sumr;
    int i, j, x, y;

    for(i = 1; i < img.rows-1; i++){
        for(j = 1; j < img.cols-1; j++){
            sumb = sumg = sumr = 0.0;
            for(x = -1; x < kernel_size-1; x++){
                for(y = -1; y < kernel_size-1; y++){
                    sumb += img.at<Vec3b>(i + x, j + y)[0];
                    sumg += img.at<Vec3b>(i + x, j + y)[1];
                    sumr += img.at<Vec3b>(i + x, j + y)[2];
                }
            }
            img.at<Vec3b>(i, j)[0] = (int)(sumb/kernel);
            img.at<Vec3b>(i, j)[1] = (int)(sumg/kernel);
            img.at<Vec3b>(i, j)[2] = (int)(sumr/kernel);
        }
    }

    namedWindow("Filter", WINDOW_AUTOSIZE);
    imshow("Filter", img);
    waitKey(0);
}
