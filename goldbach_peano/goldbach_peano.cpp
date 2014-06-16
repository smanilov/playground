#include <iostream>
#include <vector>
#include <cmath>

using std::ostream;
using std::cout;
using std::cerr;

using std::vector;

class PPMImage {
private:
        int w;
        int h;
        vector<char> red, green, blue;

        void outputHeader(ostream& os) const {
                os << "P6 " << w << " " << h << " 255\n";
        }
        void outputData(ostream& os) const {
                for (int i = 0; i < red.size(); ++i) {
                        os << red[i] << green[i] << blue[i];
                }
        }
public:
        PPMImage(int width, int height) {
                w = width;
                h = height;
                red   = vector<char>(w * h);
                green = vector<char>(w * h);
                blue  = vector<char>(w * h);

                for (int y = 0; y < h; ++y) {
                        for (int x = 0; x < w; ++x) {
                                setPixel(x, y, 0xff, 0x11, 0x00);
                        }
                }
        }
        
        bool setPixel(int x, int y, char r, char g, char b) {
                if (!(x >= 0 && x < w && y >= 0 && y < h)) {
                        return false;
                }
                int idx = (h - y - 1) * w + x;
                red  [idx] = r;
                green[idx] = g;
                blue [idx] = b;
                return true;
        }

        friend ostream& operator<<(ostream& os, const PPMImage& image) {
                image.outputHeader(os);
                image.outputData(os);
                return os;
        }
};

bool isPrime(int x) {
        if (x < 2) return false;
        int sq = (int)sqrt((double)x);
        for (int i = 2; i <= sq; ++i) {
                if (x % i == 0) return false;
        }
        return true;
}

bool drawSpiralPixel(PPMImage& image, int x0, int y0, double r, double theta, double num) {
        int x = (int) (x0 + r * cos(theta));
        int y = (int) (y0 + r * sin(theta));
        if (isPrime((int)(num))) {
                if (!image.setPixel(x, y, 0xff, 0xff, 0x00)) {
                        return false;
                }
        } else {
                if (!image.setPixel(x, y, 0x00, 0x00, 0x00)) {
                        return false;
                }
        }
        return true;
}

void drawSpiral(PPMImage& image, int x0, int y0) {
        double b = 2.0;
        double dtheta = 1e-1;

        double scale = 0.01;
        for (double theta = 0.0; ; theta += dtheta) {
                double r = b * theta;
                double num = theta * r * scale;
                if (!drawSpiralPixel(image, x0, y0, r, theta, num)) {
                        break;
                }
                drawSpiralPixel(image, x0, y0, r - 1.0, theta, num);
                drawSpiralPixel(image, x0, y0, r - 0.5, theta, num);
                drawSpiralPixel(image, x0, y0, r + 0.5, theta, num);
                drawSpiralPixel(image, x0, y0, r + 1.0, theta, num);
                if (r > 10.0) {
                        dtheta = 1 / r;
                }
        }
}

bool testIsPrime() {
        bool ans[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0};
        for (int i = 0; i < 50; ++i) {
                if (isPrime(i) != ans[i]) {
                        return false;
                }
        }
        return true;
}

int main()
{
        static const int W = 300;
        static const int H = 300;

        PPMImage img(W, H);

        drawSpiral(img, W/2, H/2);

        cout << img;
}
