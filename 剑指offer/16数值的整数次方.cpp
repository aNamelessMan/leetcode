#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了70.75% 的用户
double myPow(double x, int n) {
    if(n == 0)return 1;
    if(n < 0)return myPow(1 / x, -(long)n - 1) * (1 / x);//直接取负数，会因为int范围并不是关于0对称而可能溢出
    double res = x;
    long cnt = 1;
    while(cnt * 2 <= n){
        res *= res;
        cnt *= 2;
    }
    return res * myPow(x, n - cnt);
}

int main(){
    cout << "print sth." << endl;
}