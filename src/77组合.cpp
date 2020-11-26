#include<bits/stdc++.h>
using namespace std;

// 执行用时：36 ms, 在所有 C++ 提交中击败了65.25% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了81.75% 的用户
void dfs(int n, int k, vector<vector<int>> &res, int cur, int cnt, vector<int> &t){
    if(cnt == k){
        res.push_back(t);
        return;
    }else{
        for(int i = cur; i <= n; i++){
            t.push_back(i);
            dfs(n, k, res, i + 1, cnt + 1, t);
            t.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if(n < k || k == 0)return res;
    vector<int> t;
    dfs(n, k, res, 1, 0, t);
    return res;
}

int main(){
    cout << 1 << endl;
}