#include <bits/stdc++.h>

using namespace std;

bool check(double val, double target) { return val * val * val > target; }

double bs(double l, double r, double target) {
  while (r - l > 1e-8) {
    double mid = (l + r) / 2;
    if (check(mid, target)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}

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

  // cout输出默认精度为6位有效数，所以不一定会保留到六位小数
  cout << sqrt_n(5.30) << endl;
  // setprecision设定的是有效位数，不是小数点后位数
  cout << setprecision(6) << sqrt_n(5.30) << endl;
  // cout << setiosflags(ios::fixed);
  // 只有在这项设置后，setprecision才是设置小数的位数
  cout << fixed << setprecision(6) << sqrt_n(5.30) << endl;

  // 可以用printf指定位数
  printf("%.6lf\n", sqrt_n(5.30));
}
