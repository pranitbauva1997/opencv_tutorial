#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat final_img(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    cvtColor(img, img1, CV_BGR2GRAY);

    int gx, gy, g;
    gx = gy = g = 0;
    int i, j, x, y;
    int kernel1[3][3]={{-1, 0, +1},
                      {-2, 0, +2},
                      {-1, 0, +1}};
    int kernel2[3][3]={{1, 2, 1},
                       {0, 0, 0},
                       {-1, -2, -1}};

    for(i = 1; i < img.rows-1; i++){
        for(j = 1; j < img.cols-1; j++){
            gx = gy = g = 0;
            for(x = -1; x < 2; x++){
                for(y = -1; y < 2; y++){
                    gx += img1.at<uchar>(i + x, j + y) * kernel1[1+x][y+1];
                    gy += img1.at<uchar>(i + x, j + y) * kernel2[1+x][y+1];
                }
            }
            g = sqrt(gx*gx + gy*gy);
            if(g > 255)
                g = 255;
                final_img.at<uchar>(i, j) = g;
        }
    }

    namedWindow("Filter", WINDOW_AUTOSIZE);
    imshow("Filter", final_img);
    waitKey(0);
}
