#include<iostream>
#include<stack>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

typedef struct{
    int x;
    int y;
} point;

Mat img;
int visited[1000][1000];

void DFS(point p){
    int i, j;
    stack<point> s;
    s.push(p);
    point temp;
    while(!s.empty()){
        point A = s.top();
        s.pop();
        visited[A.x][A.y] = 1;

        // Finding other nodes
        for(i = -1; i < 2; i++){
            for(j = -1; j < 2; j++){
                temp.x = A.x + i;
                temp.y = A.x + j;
                if((img.at<uchar>(temp.x, temp.y) == 0) && (visited[temp.x][temp.y] == 0))
                    s.push(temp);
            }
        }
    }
}

int main(int argc, char **argv){
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    Mat img1(img.rows, img.cols, CV_8UC1, Scalar(0));
    Mat img2(img.rows, img.cols, CV_8UC1, Scalar(0));
    Mat final_img(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
    cvtColor(img, img1, CV_BGR2GRAY);
    int i, j;

    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", img);
    namedWindow("Binary", WINDOW_AUTOSIZE);;
    // Binary image
    for(i = 0; i < img1.rows; i++)
        for(j = 0; j < img1.cols; j++)
            if(img1.at<uchar>(i, j) > 127)
                img2.at<uchar>(i, j) = 255;
    imshow("Binary", img2);


    // Initialise a array named visited
    for(i = 0; i < img.rows; i++)
        for(j = 0; j < img.cols; j++)
            visited[i][j] = 0;

    // Applying DFS
    point p;
    for(i = 1; i < img2.rows - 1; i++){
        for(j = 1; j < img2.cols - 1; j++){
            p.x = i;
            p.y = j;
            if((img2.at<uchar>(i, j) == 0) && visited[i][j] == 0)
                DFS(p);
        }
    }

    // Marking the blob red
    for(i = 0; i < img2.rows; i++)
        for(j = 0; j < img2.rows; j++)
            if(visited[i][j])
                final_img.at<Vec3b>(i, j)[2] = 255;

    namedWindow("YES", WINDOW_AUTOSIZE);
    imshow("YES", final_img);
    waitKey(0);
    return 0;
}
