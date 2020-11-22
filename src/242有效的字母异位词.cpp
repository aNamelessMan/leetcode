#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了63.62% 的用户
// 内存消耗：7.8 MB, 在所有 C++ 提交中击败了5.08% 的用户
bool isAnagram(string s, string t) {
    int m = s.size(), n = t.size();
    if(m != n)return false;
    if(m == 0)return true;
    unordered_map<char, int> cnt;
    for(int i = 0; i < m; i++){
        cnt[s[i]]++;
        cnt[t[i]]--;
    }
    for(auto &p: cnt){
        if(p.second != 0)return false;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}