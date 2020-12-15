#include<bits/stdc++.h>
using namespace std;

// 执行用时：180 ms, 在所有 C++ 提交中击败了8.30% 的用户
// 内存消耗：48.5 MB, 在所有 C++ 提交中击败了12.25% 的用户
bool isP(string s){
    int n = s.size();
    if(n == 1)return true;
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1])return false;
    }
    return true;
}

void dfs(int start, int n, vector<vector<string>> &res, vector<string> &t, string &s){
    if(start == n){
        res.push_back(t);
        return;
    }
    for(int l = 1; start + l <= n; l++){
        if(isP(s.substr(start, l))){
            t.push_back(s.substr(start, l));
            dfs(start + l, n, res, t, s);
            t.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> res;
    vector<string> t;

    dfs(0, n, res, t, s);

    return res;
}

int main(){
    cout << 1 << endl;
}