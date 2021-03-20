#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.7 MB, 在所有 C++ 提交中击败了59.74% 的用户
string addStrings(string num1, string num2) {
    int carry = 0, m = num1.size(), n = num2.size();
    if(m == 0)return num2;
    if(n == 0)return num1;
    string res;
    int i1 = m - 1, i2 = n - 1;
    while(i1 >= 0 || i2 >= 0 || carry){
        int s = (i1 >= 0?num1[i1] - '0':0) + (i2 >= 0?num2[i2] - '0':0) + carry, a = s % 10;
        i1--;
        i2--;
        carry = s / 10;
        res.push_back(a + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << "print something." << endl;
}