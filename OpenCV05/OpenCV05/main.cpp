//
//  main.cpp
//  OpenCV05
//
//  Created by 陈江林 on 2019/9/8.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //修改像素值
    string filePath = "/Users/chenjianglin/Documents/C++/OpenCV05/OpenCV05/OpenCV05/tupian.jpg";
    Mat image = imread(filePath);
    if (image.empty()) {
        cout << "无法读取数据" << endl;
        return -1;
    }
    Mat outImage;
    cvtColor(image, outImage, COLOR_BGR2GRAY);
    int cols = outImage.cols;
    int rows = outImage.rows;
    int channels = outImage.channels();
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (channels == 1) {
                // 对灰度值求反色
                int value = outImage.at<uchar>(row, col);
                outImage.at<uchar>(row, col) = 255 - value;
            }else if (channels == 3){
                // 对grb值求反色
            }
        }
    }
    
    string grayWindow = "grayWindow";
    namedWindow(grayWindow);
    imshow(grayWindow, outImage);
    
    
    Mat m2;
    cvtColor(image, m2, COLOR_BGR2RGBA);
    int height = m2.rows;
    int width = m2.cols;
    int nels = m2.channels();
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            uchar val = m2.at<uchar>(row, col);
            if (nels == 4) {
                int r = m2.at<Vec4b>(row, col)[0];
                int g = m2.at<Vec4b>(row, col)[1];
                int b = m2.at<Vec4b>(row, col)[2];
                int a = m2.at<Vec4b>(row, col)[3];
                // 求反色
                m2.at<Vec4b>(row, col)[0] = 255 - r;
                m2.at<Vec4b>(row, col)[1] = 255 - g;
                m2.at<Vec4b>(row, col)[2] = 255 - b;
//                m2.at<Vec4b>(row, col)[3] = 255 - a;
                
            }
            if (val == GC_PR_BGD) {
                m2.at<Vec4b>(row, col)[0] = 255;
                m2.at<Vec4b>(row, col)[1] = 255;
                m2.at<Vec4b>(row, col)[2] = 255;
                m2.at<Vec4b>(row, col)[3] = 255;
            }
        }
    }
    
    string m2Window = "m2 Window";
    namedWindow(m2Window);
    imshow(m2Window, m2);
    
    
    
    waitKey(0);
    return 0;
}
