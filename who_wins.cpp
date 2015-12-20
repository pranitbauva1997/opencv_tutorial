#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int range(int x, int y, int d){
    if(x >= y - d && x <= y + d)
        return 1;
    else if(y >= x - d && y <= x + d)
        return 1;
    else
        return 0;
}

vector<Point> corrector(vector<Point> v){
    vector<Point> l;
    int i, j, flag;
    for(i = 0; i < v.size(); i++){
        flag = 1;
        for(j = 0; j < l.size(); j++){
            if(range(l[j].x, v[i].x, 5))
                flag = 0;
        }
        if(flag)
            l.push_back(v[i]);
    }


    return l;
}

int main(){
    Mat src1, src2;
    Mat src1_gray, src2_gray;
    Mat canny1, canny2;
    vector<vector<Point> > contours1, contours2;
    vector<Vec4i> hierarchy1, hierarchy2;
    VideoCapture cap("video.avi");
    float t1, t2;
    t1 = 900;
    t2 = 1500;

    if(!cap.isOpened()){
        cout << "Sorry there was some problem playing the video" << endl;
        return -1;
    }

    // Store various instances of frames of video
    cap.set(CV_CAP_PROP_POS_MSEC, t1);
    cap >> src1;
    cap.set(CV_CAP_PROP_POS_MSEC, t2);
    cap >> src2;

    // Convert image to gray and blur it
    cvtColor(src1, src1_gray, CV_BGR2GRAY);
    cvtColor(src2, src2_gray, CV_BGR2GRAY);
    blur(src1_gray, src1_gray, Size(3, 3));
    blur(src2_gray, src2_gray, Size(3, 3));

    // Applying Canny for edge Detection
    Canny(src1_gray, canny1, 10, 30, 3);
    Canny(src2_gray, canny2, 10, 30, 3);

    // Find contours
    findContours(canny1, contours1, hierarchy1, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    findContours(canny2, contours2, hierarchy2, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    // Get centres of contours
    int i, j;
    int tempx, tempy;
    vector<Point> centres1_, centres2_, centres1, centres2;
    for(i = 0; i < contours1.size(); i++){
        tempx = tempy = 0;
        for(j = 0; j < contours1[i].size(); j++){
            tempx += contours1[i][j].x;
            tempy += contours1[i][j].y;
        }
        centres1_.push_back(Point(tempx/j, tempy/j));
    }
    for(i = 0; i < contours2.size(); i++){
        tempx = tempy = 0;
        for(j = 0; j < contours2[i].size(); j++){
            tempx += contours2[i][j].x;
            tempy += contours2[i][j].y;
        }
        centres2_.push_back(Point(tempx/j, tempy/j));
    }

    centres1 = corrector(centres1_);
    centres2 = corrector(centres2_);

    vector<float> a;
    vector<float> u;
    float y1, y2;
    y1 = y2 = 0;
    for(i = 0; i < centres1.size(); i++){
        y1 = centres1[i].y;
        y2 = centres2[i].y;
        u.push_back((y2*t1*t1 - y1*t2*t2)/t1/t2/(t1-t2));
        a.push_back((y1*t2 - y2*t1)/t1/t2/(t2-t1));
    }

    vector<float> position;
    float t_final = 8000;
    for(i = 0; i < a.size(); i++)
        position.push_back(u[i]*t_final + t_final*t_final*0.5*a[i]);

    for(i = 0; i < a.size(); i++)
        cout << "x = " << position[i] << endl;

    for(i = 0; i < centres1.size(); i++)
        cout << centres1[i] << endl;









    imshow("src1", canny1);
    imshow("src2", canny2);

    if(waitKey(0) == 'q')
        return 0;
}
