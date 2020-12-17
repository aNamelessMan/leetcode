#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.3 MB, 在所有 C++ 提交中击败了17.67% 的用户
string convertToTitle(int n) {
    string res;
    while(n){
        n--;
        int t = n % 26;
        res += 'A' + t;
        n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << 1 << endl;
}