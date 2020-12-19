#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了28.87% 的用户
int titleToNumber(string s) {
    int res = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        res = res * 26 - 'A' + s[i] + 1;//先减'A'再加防止溢出
    }
    return res;
}

int main(){
    cout << 1 << endl;
}