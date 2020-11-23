#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了44.93% 的用户
string addBinary(string a, string b) {
    if(a == "0")return b;
    if(b == "0")return a;
    int m = a.size(), n = b.size(), cnt = max(m, n);
    string res;
    int i = 0, carry = 0, r = 0;
    while(i < cnt || carry){
        if(i < m && i < n){
            r = a[m - i - 1] - '0' + b[n - i - 1] - '0' + carry;
        }else if(i < m && i >= n){
            r = a[m - i - 1] - '0' + carry;
        }else if(i >= m && i < n){
            r = b[n - i - 1] - '0' + carry;
        }else{
            r = carry;
        }
        if(r > 1){
            res.push_back(r - 2 + '0');
            carry = 1;
        }else{
            res.push_back(r + '0');
            carry = 0;
        }
        i++;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << 1 << endl;
}