#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了28.08% 的用户
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size(), carry = 1;
    vector<int> res;
    for(int i = n - 1; i >= 0; i--){
        int r = carry + digits[i];
        if(r > 9){
            carry = 1;
            res.push_back(r - 10);
        }else{
            carry = 0;
            res.push_back(r);
        }
    }
    if(carry)res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << 1 << endl;
}