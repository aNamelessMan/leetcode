#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了72.88% 的用户
//就是找规律... 不能像之前那样dp了，因为取余之后的乘积比较大小没有意义
int cuttingRope(int n) {
    if(n == 2)return 1;
    if(n == 3)return 2;
    long res = 1;
    while(n >= 5){//大于等于5时3越多乘积越大
        res *= 3;
        res %= int(1e9 + 7);
        n -= 3;
    }
    return res * n % int(1e9 + 7);
}

int main(){
    cout << "print sth." << endl;
}