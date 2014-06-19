#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using std::stoi;
using std::stod;

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

static int count = 0;
static int count2 = 0;

bool drawSpiralPixel(PPMImage& image, int x0, int y0, double r, double theta,
                int num, int circum0, int mod0, const RGB24bit& primeColor, const RGB24bit& compositeColor) {
        int x = (int) (x0 + r * cos(theta));
        int y = (int) (y0 + r * sin(theta));

        RGB24bit evenColor = compositeColor;
        evenColor.red   /= 2;
        evenColor.green /= 2;
        evenColor.blue  /= 2;

        RGB24bit specColor = { 0xff, 0xff, 0x00 };

        static int circum = circum0;
        static int mod = mod0;
        if (num == mod + 1) {
//                if (isPrime(mod)) {
//                        cerr << "\t" << mod << '\n';
//                }
                ++count;
                mod += circum;
                circum += 8;
        }
        if (isPrime(num)) {
                if (!image.setPixel(x, y, primeColor)) {
                        return false;
                }
        } else {
                if (num == mod) {
                        if (!image.setPixel(x, y, specColor)) {
                                return false;
                        }
                        count2++;
                } else {
                        if (num % 2 == 0) {
                                if (!image.setPixel(x, y, evenColor)) {
                                        return false;
                                }
                        } else {
                                if (!image.setPixel(x, y, compositeColor)) {
                                        return false;
                                }
                        }
                }
        }
        return true;
}

void drawSpiral(PPMImage& image, int x0, int y0, double b, double scale, int lineWidth, int circum0, int mod0, const RGB24bit& primeColor, const RGB24bit& compositeColor) {
        double dtheta = 1e-1;

        for (double theta = 0.0; ; theta += dtheta) {
                double r = b * theta;
                double num = theta * r * scale;
                double dr = -((double)(lineWidth - 1)) / 2;
                for (int i = 0; i < lineWidth; ++i) {
                        if (!drawSpiralPixel(image, x0, y0, r + dr, theta, num, circum0, mod0, primeColor, compositeColor)) {
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
        cerr << "Usage: " << argv[0] << " <width> <height> <b> <scale> <line-width> <circum0> <mod0> <background-red> "
                "<...-green> <...-blue> <prime-red> <...-green> <...-blue> "
                "<composite-red> <...-green> <...-blue>\n";
}

int main(int argc, char **argv)
{
        int W = 500;
        int H = 500;

        int lineWidth = 5;

        double b = 1.0;
        double scale = 0.1;

        int circum0 = 14;
        int mod0 = 47;

        RGB24bit backgroundColor = {0x00, 0x00, 0x00};
        RGB24bit primeColor = {0xff, 0x00, 0x00};
        RGB24bit compositeColor = {0x80, 0x80, 0x80};

        if (argc > 1) {
                if (argc != 17) {
                        usage(argc, argv);
                        return 1;
                } else {
                        W                     = stoi(argv[1]);
                        H                     = stoi(argv[2]);

                        b                     = stod(argv[3]);
                        scale                 = stod(argv[4]);

                        lineWidth             = stoi(argv[5]);

                        circum0               = stoi(argv[6]);
                        mod0                  = stoi(argv[7]);

                        backgroundColor.red   = stoi(argv[8]);
                        backgroundColor.green = stoi(argv[9]);
                        backgroundColor.blue  = stoi(argv[10]);

                        primeColor.red        = stoi(argv[11]);
                        primeColor.green      = stoi(argv[12]);
                        primeColor.blue       = stoi(argv[13]);

                        compositeColor.red    = stoi(argv[14]);
                        compositeColor.green  = stoi(argv[15]);
                        compositeColor.blue   = stoi(argv[16]);
                }
        }

        PPMImage img(W, H, backgroundColor);

        drawSpiral(img, W/2, H/2, b, scale, lineWidth, circum0, mod0, primeColor, compositeColor);
        cout << img;

        if (count2 < 300) {
                cerr << count << '\n';
                cerr << count2 << '\n';
        }
}
