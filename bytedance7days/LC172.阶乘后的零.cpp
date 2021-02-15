#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了76.23% 的用户
int trailingZeroes(int n) {
    /*0必须是2*5获得
    同时因为是阶乘，所以5的个数一定小于2的个数，因此只统计因子中5的个数即可
    也就是统计5的c次方，将所有的c加起来即可
    */
    int res = 0;
    while(n){
        res += n / 5;
        n /= 5;
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}