#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了49.09% 的用户
int hammingWeight(uint32_t n) {
    int res = 0;
    while(n){
        if(n % 2)res++;
        n /= 2;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}