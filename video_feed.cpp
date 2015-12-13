#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    VideoCapture cap(argv[1]);

    // Check validity
    if(!cap.isOpened()){
        cout << "Sorry there is some problem with the video feed." << endl;
        return -1;
    }
    int i = 0;
    namedWindow("Video", WINDOW_AUTOSIZE);
    Mat frameReference, frameUnderTest;
    while(1){
        cap >> frameReference;
        cap.set(CV_CAP_PROP_POS_MSEC, 3000 * i);
        imshow("Video", frameReference);
        if(waitKey(50) == 'q')
            break;
        i++;
    }
}
