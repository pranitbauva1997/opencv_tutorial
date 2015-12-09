#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int range(int x, int y, int tol){
    if(x > y - tol && x < y + tol)
        return 1;
    else if(y > x - tol && y < x + tol)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv){
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat final_img(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));

    namedWindow("Color Extractor", WINDOW_AUTOSIZE);
    int red, blue, green, tol;
    red = blue = green = tol = 0;
    int i, j;

    createTrackbar("Blue", "Color Extractor", &blue, 255);
    createTrackbar("Green", "Color Extractor", &green, 255);
    createTrackbar("Red", "Color Extractor", &red, 255);
    createTrackbar("Tolerance", "Color Extractor", &tol, 50);
    while(1){
        for(i = 0; i < img.rows; i++){
            for(j = 0; j < img.cols; j++){
                if(range(img.at<Vec3b>(i, j)[0], blue, tol) && range(img.at<Vec3b>(i, j)[1], green, tol) && range(img.at<Vec3b>(i, j)[2], red, tol)){
                    final_img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j);
                }
                else{
                    final_img.at<Vec3b>(i, j)[0] = 255;
                    final_img.at<Vec3b>(i, j)[1] = 255;
                    final_img.at<Vec3b>(i, j)[2] = 255;
                }
            }
        }
        imshow("Color Extractor", final_img);
        if(waitKey(10) == 'q')
            break;
    }
    return 0;
}
