#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了9.62% 的用户
void dfs(string &s, int start, int n, vector<string> &res, string tmp, int ts){
    if(start == n && ts == 4){
        res.push_back(tmp);
        return;
    }else if(start == n){
        return;
    }else if(ts == 4){
        return;
    }
    if(ts != 0)tmp += '.';
    if(start < n){
        tmp += s.substr(start, 1);
        dfs(s, start + 1, n, res, tmp, ts + 1);
        tmp.pop_back();
    }
    if(start < n - 1){
        tmp += s.substr(start, 2);
        if(s[start] == '0')return;
        dfs(s, start + 2, n, res, tmp, ts + 1);
        tmp.pop_back();
        tmp.pop_back();
    }
    if(start < n - 2){
        int c = stoi(s.substr(start, 3));
        if(s[start] == '0')return;
        if(c > 255 || c < 0)return;
        tmp += s.substr(start, 3);
        dfs(s, start + 3, n, res, tmp, ts + 1);
        tmp.pop_back();
        tmp.pop_back();
        tmp.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> res;
    dfs(s, 0, n, res, {}, 0);
    return res;
}

int main(){
    cout << 1 << endl;
}