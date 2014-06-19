#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using std::stoi;

using std::ostream;
using std::cout;
using std::cerr;

using std::vector;

typedef unsigned char uchar_t;

struct RGB24bit {
        uchar_t red;
        uchar_t green;
        uchar_t blue;
};

class PPMImage {
private:
        int w;
        int h;
        vector<RGB24bit> pixels;

        void outputHeader(ostream& os) const {
                os << "P6 " << w << " " << h << " 255\n";
        }
        void outputData(ostream& os) const {
                for (int i = 0; i < pixels.size(); ++i) {
                        os << pixels[i].red << pixels[i].green << pixels[i].blue;
                }
        }
public:
        PPMImage(int width, int height) {
                w = width;
                h = height;
                pixels = vector<RGB24bit>(w * h);
        }

        PPMImage(int width, int height, const RGB24bit& backgroundColor)
        : PPMImage(width, height) {
                for (int y = 0; y < h; ++y) {
                        for (int x = 0; x < w; ++x) {
                                setPixel(x, y, backgroundColor);
                        }
                }
        }
        
        bool setPixel(int x, int y, const RGB24bit& color) {
                if (!(x >= 0 && x < w && y >= 0 && y < h)) {
                        return false;
                }
                int idx = (h - y - 1) * w + x;
                pixels[idx] = color;
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

bool drawSpiralPixel(PPMImage& image, int x0, int y0, double r, double theta,
                double num, const RGB24bit& primeColor, const RGB24bit& compositeColor) {
        int x = (int) (x0 + r * cos(theta));
        int y = (int) (y0 + r * sin(theta));
        if (isPrime((int)(num))) {
                if (!image.setPixel(x, y, primeColor)) {
                        return false;
                }
        } else {
                if (!image.setPixel(x, y, compositeColor)) {
                        return false;
                }
        }
        return true;
}

void drawSpiral(PPMImage& image, int x0, int y0, int lineWidth, const RGB24bit& primeColor, const RGB24bit& compositeColor) {
        double b = 2.0;
        double dtheta = 1e-1;

        double scale = 0.01;
        for (double theta = 0.0; ; theta += dtheta) {
                double r = b * theta;
                double num = theta * r * scale;
                double dr = -((double)(lineWidth - 1)) / 2;
                for (int i = 0; i < lineWidth; ++i) {
                        if (!drawSpiralPixel(image, x0, y0, r + dr, theta, num, primeColor, compositeColor)) {
                                goto end;
                        }
                        dr += 0.5;
                }
                if (r > 10.0) {
                        dtheta = 1 / r;
                }
        }
end:
        return;
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

void usage(int argc, char **argv) {
        cerr << "Usage: " << argv[0] << " <width> <height> <line-width> <background-red> "
                "<...-green> <...-blue> <prime-red> <...-green> <...-blue> "
                "<composite-red> <...-green> <...-blue>\n";
}

int main(int argc, char **argv)
{
        int W = 300;
        int H = 300;

        int lineWidth = 5;

        RGB24bit backgroundColor = {0xff, 0x11, 0x00};
        RGB24bit primeColor = {0xff, 0xff, 0x00};
        RGB24bit compositeColor = {0x00, 0x00, 0x00};

        if (argc > 1) {
                if (argc != 13) {
                        usage(argc, argv);
                        return 1;
                } else {
                        W                     = stoi(argv[1]);
                        H                     = stoi(argv[2]);

                        lineWidth             = stoi(argv[3]);

                        backgroundColor.red   = stoi(argv[4]);
                        backgroundColor.green = stoi(argv[5]);
                        backgroundColor.blue  = stoi(argv[6]);

                        primeColor.red        = stoi(argv[7]);
                        primeColor.green      = stoi(argv[8]);
                        primeColor.blue       = stoi(argv[9]);

                        compositeColor.red    = stoi(argv[10]);
                        compositeColor.green  = stoi(argv[11]);
                        compositeColor.blue   = stoi(argv[12]);
                }
        }

        PPMImage img(W, H, backgroundColor);

        drawSpiral(img, W/2, H/2, lineWidth, primeColor, compositeColor);

        cout << img;
}
