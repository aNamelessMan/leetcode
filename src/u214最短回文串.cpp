#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了96.04% 的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了87.62% 的用户
//没看懂...
string shortestPalindrome(string s) {
    int i = 0, n = s.size();
    for (int j = n - 1; j >= 0; --j) {
        if (s[i] == s[j]) ++i;
    }
    if (i == n) return s;
    string rem = s.substr(i);
    reverse(rem.begin(), rem.end());
    return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
}

//120 / 120 个通过测试用例  TLE
string BFshortestPalindrome(string s) {
    int n = s.size();
    string res;
    int i = n / 2, l = i, r = i, sign = 1;
    while(i >= 0 && i < n){//i是打算作为中间轴或者作为无对称轴回文串的左边那个字符
        int ll = i, rl = n - i - 1;//分别是i左边/右边的字符数
        //作为无对称轴回文串的左边那个字符的情况
        int j = 0;
        while(j <= ll && j <= rl - 1){
            if(s[i - j] != s[i + j + 1])break;
            j++;
        }
        if(j > ll){
            int num = rl - ll;
            for(int k = 0; k < num - 1; k++){
                res.push_back(s[n - 1 - k]);
            }
            res += s;
            return res;
        }
        //作为中间轴的情况
        j = 1;
        while(j <= ll && j <= rl){
            if(s[i - j] != s[i + j])break;
            j++;
        }

        if(j > ll){
            int num = rl - ll;
            for(int k = 0; k < num; k++){
                res.push_back(s[n - 1 - k]);
            }
            res += s;
            return res;
        }

        i--;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}