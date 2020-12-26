#include<bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了37.64% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了12.13% 的用户
//和290题一模一样
bool isIsomorphic(string s, string t) {
    unordered_map<char, int> sm;
    unordered_map<char, int> tm;
    int m = s.size(), n = t.size();
    if(m != n)return false;
    for(int i = 0; i < m; i++){
        if(sm.find(s[i]) == sm.end())sm[s[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(tm.find(t[i]) == tm.end())tm[t[i]] = i;
    }

    for(int i = 0; i < m; i++){
        if(sm[s[i]] != tm[t[i]])return false;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}