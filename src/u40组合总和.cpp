#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了81.49% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了26.48% 的用户
void dfs(vector<vector<int>> &res, vector<int>& candidates, int target, vector<int> &cur, int previ){
    if(target == 0){
        res.push_back(cur);
        return;
    }
    if(target < 0)return;
    for(int i = previ; i < (int)candidates.size(); i++){
        if(i != previ && candidates[i] == candidates[i - 1])//这一步是为了去重
            continue;
        else{
            cur.push_back(candidates[i]);
            target -= candidates[i];
            dfs(res, candidates, target, cur, i + 1);
            target += candidates[i];
            cur.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());//为了去重所以先排序
    vector<int> cur;
    dfs(res, candidates, target, cur, 0);
    return res;
}

int main(){
    cout << 1 << endl;
}