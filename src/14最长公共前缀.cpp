#include<bits/stdc++.h>
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了8.68% 的用户
// 内存消耗：9 MB, 在所有 C++ 提交中击败了8.00% 的用户
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())return "";
    string res;
    int ms = INT_MAX;
    for(auto &s:strs){
        if(s.size() < ms)ms = s.size();
    }
    for(int i = 0; i < ms; i++){
        char c = strs[0][i];
        for(auto &s:strs){
            if(s[i] != c)return res;//遇到不符直接返回即可，不用继续流程
        }
        res += c;
    }
    return res;
}

int main(){
    // vector<string> strs{"flower","flow","flight"};
    vector<string> strs{"dog","racecar","car"};
    cout << longestCommonPrefix(strs) << endl;
}