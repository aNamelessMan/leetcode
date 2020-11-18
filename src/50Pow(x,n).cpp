#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了9.06% 的用户
//递归解法  很简单
//只要注意参数范围  n可以是负数，其数值范围是 [−2^31, 2^31 − 1]因此i用int可能会溢出
double myPow(double x, int n) {
    if(x == 0)return 0;
    if(n == 0)return 1;

    if(n > 0){
        long i = 1;
        double res = x;
        while(2 * i <= n){
            res = res * res;
            i *= 2;
        }
        return res * myPow(x, n - i);
    }else{
        long i = -1;
        double res = 1 / x;
        while(2 * i >= n){
            res = res * res;
            i *= 2;
        }
        return res * myPow(x, n - i);
    }
}

int main(){
    cout << 1 << endl;
}