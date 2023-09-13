#include <iostream>

using namespace std;

static int n = 3;
// 求n次方根，浮点数二分，更简单
double sqrt_n(double x) {
    // 解的范围，题目给的
    double l = -10000, r = 10000;
    // 一般要求保留6位，r - l > 1e-8    大2位
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        double t = 1;
        for (int i = 0; i < 3; i++) {
            t *= mid;
        }
        if (t < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cout << sqrt_n(8.0) << endl;
    cout << sqrt_n(1000.0) << endl;
    cout << sqrt_n(300.0) << endl;
}
