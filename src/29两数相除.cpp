#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了94.35% 的用户
int divide(int dividend, int divisor) {
    bool sign;
    if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
        sign = true;
    }else{
        sign = false;
    }
    long dived = labs(dividend);//必须重新定义两个long来存，因为INT_MIN取绝对值会溢出
    long disor = labs(divisor);
    if(dived == 0 || dived < disor)return 0;
    long res = 0, cnt = 1, base = disor;
    while(dived >= base){
        res += cnt;
        dived -= base;
        cnt <<= 1;//单纯的移位操作不会改变变量值，必须加上=
        base <<= 1;
    }
    res += divide(dived, disor);
    if(!sign)res = -res;
    return res > INT_MAX?INT_MAX:res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.3 MB, 在所有 C++ 提交中击败了5.28% 的用户
int fstdivide(int dividend, int divisor) {
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
    cout << divide(-2147483648, 1) << endl;
}