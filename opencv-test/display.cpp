#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <cmath>
#include "trav.h"

const int SECOND = 1000000;

using std::cerr;

using namespace cv;

bool isPrime(int x) {
        if (x < 2) return false;
        int sq = (int)sqrt((double)x);
        for (int i = 2; i <= sq; ++i) {
                if (x % i == 0) return false;
        }
        return true;
}

int main(int argc, char** argv) {
        Mat image(1028, 1028, CV_8UC3, Scalar(0, 0, 0));

        namedWindow("Display Image", WINDOW_AUTOSIZE);
        
//        imshow("Display Image", image);

        int x = 0, y = 1027;
        traversal peano = traversal().next().next().next().next().next().next().next().next().next();

        Vec3b composite_col = {0, 64, 128};
        Vec3b prime_col = {255, 255, 255};
        int count = 0;
        for (auto& d : peano.dirs) {
                if (composite_col.val[2] > 64 && composite_col.val[1] == 64) {
                        composite_col.val[2]--;
                } else if (composite_col.val[1] < 128 && composite_col.val[2] == 64) {
                        composite_col.val[1]++;
                } else if (composite_col.val[2] < 128) {
                        composite_col.val[2]++;
                } else {
                        composite_col.val[1]--;
                }
                if (composite_col.val[1] == 64 && composite_col.val[2] == 128) {
                        composite_col.val[0]++;
                }
                switch (d.val) {
                case 'u':
                        image.at<Vec3b>(y, x) = composite_col;
                        y -= 1;
                        image.at<Vec3b>(y, x) = isPrime(count)? prime_col: composite_col;
                        y -= 1;
                        break;
                case 'r':
                        image.at<Vec3b>(y, x) = composite_col;
                        x += 1;
                        image.at<Vec3b>(y, x) = isPrime(count)? prime_col: composite_col;
                        x += 1;
                        break;
                case 'd':
                        image.at<Vec3b>(y, x) = composite_col;
                        y += 1;
                        image.at<Vec3b>(y, x) = isPrime(count)? prime_col: composite_col;
                        y += 1;
                        break;
                case 'l':
                        image.at<Vec3b>(y, x) = composite_col;
                        x -= 1;
                        image.at<Vec3b>(y, x) = isPrime(count)? prime_col: composite_col;
                        x -= 1;
                        break;
                }
//                if (0 == count % 100) {
//                        if (waitKey(1) >= 0) break;
//                        imshow("Display Image", image);
//                }
                ++count;
        }

//        waitKey(0);
        imshow("Display Image", image);
        waitKey(0);

        return 0;
}
