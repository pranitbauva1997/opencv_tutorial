#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img_d(img.rows*2, img.cols*2, CV_8UC3, Scalar(0, 0, 0));

    int x, y, i, j;
    for(x = 0; x < img.rows; x++)
        for(y = 0; y < img.cols; y++)
            for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                    img_d.at<Vec3b>(x*2+i, y*2+j) = img.at<Vec3b>(x, y);

    namedWindow("Single", WINDOW_AUTOSIZE);
    namedWindow("Double", WINDOW_AUTOSIZE);
    imshow("Single", img);
    imshow("Double", img_d);

    waitKey(0);
    return 0;
}
