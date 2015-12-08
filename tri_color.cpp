#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat image(120, 300, CV_8UC3, Scalar(0, 0, 0));

    int i, j;
    for(i = 0; i < image.cols; i++){
        for(j = 0; j < image.rows/3; j++)
            image.at<Vec3b>(j, i)[2] = 255;
        for(; j < image.rows*2/3; j++)
            image.at<Vec3b>(j, i)[0] = 255;
        for(;j < image.rows; j++)
            image.at<Vec3b>(j, i)[1] = 255;
    }

    imshow("Tri Color", image);
    waitKey(0);

    return 0;
}
