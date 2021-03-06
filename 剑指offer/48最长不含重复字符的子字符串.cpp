#include <bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了66.17% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了23.11% 的用户
int lengthOfLongestSubstring(string s) {
    unordered_set<char> cs;
    int n = s.size();
    if(n == 0)return 0;
    int res = 0, l = 0, r = 0;
    while(r < n){
        while(r < n && !cs.count(s[r])){//先扩张
            cs.insert(s[r]);
            r++;
        }
        res = max(res, r - l);//只有此时才可能更新最大值
        while(s[l] != s[r]){//遇到重复值开始收缩
            cs.erase(s[l]);
            l++;
        }
        l++;
        r++;
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}