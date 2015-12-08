#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv){
    Mat image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    int i,j;
    for(i = 0; i < image.rows; i++)
        for(j = 0; j < image.cols; j++)
            image.at<Vec3b>(i, n - j - 1) = im.at<Vec3b>(i, j);

    namedWindow("Split Mirror", WINDOW_AUTOSIZE);
    imshow("Split Mirror", image);
    waitKey(0);
    return 0;
}
