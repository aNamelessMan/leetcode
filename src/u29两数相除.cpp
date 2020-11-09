#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.3 MB, 在所有 C++ 提交中击败了5.28% 的用户
int divide(int dividend, int divisor) {
    long m = labs(dividend), n = labs(divisor), res = 0;//获取绝对值
    if (m < n) return 0;
    long t = n, p = 1;
    while (m > (t << 1)) {
        t <<= 1;
        p <<= 1;
    }
    res = p + divide(m - t, n);
    if ((dividend < 0) ^ (divisor < 0)) res = -res;//如果符号不同，返回负值
    return res > INT_MAX ? INT_MAX : res;
}

int main(){
    cout << 1 << endl;
}