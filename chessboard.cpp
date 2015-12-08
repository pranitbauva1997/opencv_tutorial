#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    Mat board(900, 900, CV_8UC1, Scalar(0));
    int i, j, x, y;
    x = y = 0;

    for(x = 0; x < board.rows; x += board.rows/15)
        for(y = 0; y < board.cols; y += board.cols/15)
            for(i = 0; i < 30; i++)
                for(j = 0; j < 30; j++)
                    board.at<uchar>(x + i, y + j) = 255;

    for(x = 30; x < board.rows; x += board.rows/15)
        for(y = 30; y < board.cols; y += board.cols/15)
            for(i = 0; i < 30; i++)
                for(j = 0; j < 30; j++)
                    board.at<uchar>(x + i, y + j) = 255;



    namedWindow("Chess Board", WINDOW_AUTOSIZE);
    imshow("Chess Board", board);
    waitKey(0);

    return 0;
}
