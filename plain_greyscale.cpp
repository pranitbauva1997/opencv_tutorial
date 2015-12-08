#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat image(200, 400, CV_8UC1, Scalar(45));
    imshow("Display Window", image);

    waitKey(0);
    return 0;
}
