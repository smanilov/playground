#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <cmath>

const int SECOND = 1000000;

using std::cerr;

using namespace cv;

int main(int argc, char** argv) {
        Mat image(100, 1000, CV_8UC3, Scalar(0, 0, 0));

        namedWindow("Display Image", WINDOW_AUTOSIZE);
        
        imshow("Display Image", image);

        for (int x = 0; x < 1000; ++x) {
                int y = 50 - 50 * sin(x * 4 * M_PI / 100);
                image.at<Vec3b>(y, x).val[0] = 255;
                image.at<Vec3b>(y, x).val[1] = 128;
                image.at<Vec3b>(y, x).val[2] = 0;
                waitKey(20);
                imshow("Display Image", image);
        }

        waitKey(0);

        return 0;
}
