#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat final_img(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));

    namedWindow("Hey", WINDOW_AUTOSIZE);
    int a, b, c;
    a = b = c = 1;
    int i, j;
    createTrackbar("blue", "Hey", &a, 100);
    createTrackbar("green", "Hey", &b, 100);
    createTrackbar("red", "Hey", &c, 100);
    while(1){
        for(i = 0; i < img.rows; i++){
            for(j = 0; j < img.cols; j++){
                final_img.at<Vec3b>(i, j)[0] = a*img.at<Vec3b>(i, j)[0]/100;
                final_img.at<Vec3b>(i, j)[1] = b*img.at<Vec3b>(i, j)[1]/100;
                final_img.at<Vec3b>(i, j)[2] = c*img.at<Vec3b>(i, j)[2]/100;
            }
        }
        imshow("Hey", final_img);
        if(waitKey(10) == 'q')
            break;
    }

    return 0;
}
