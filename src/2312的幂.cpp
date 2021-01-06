#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了30.30% 的用户
bool isPowerOfTwo(int n) {
    long c = 1;
    while(c < (long)n){
        c *= 2;
    }
    return c == (long)n;
}

int main(){
    cout << 1 << endl;
}