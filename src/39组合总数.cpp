#include<bits/stdc++.h>
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了70.15% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了59.98% 的用户
vector<vector<int>> res;
vector<int> tmp;
void dfs(vector<int>& candidates, int target, int cur, int previ){
    if(cur > target){//注意不需要清空tmp和cur，否则会越界，因为递归后已经逐层清空了
        // tmp.clear();
        // cur = 0;
        return;
    }else if(cur == target){
        res.push_back(tmp);
        // tmp.clear();
        // cur = 0;
        return;
    }else{
        for(int i = 0; i < (int)candidates.size(); i++){
            if(i < previ)continue;//这一步是为了去重，观察可得只要迭代到的元素不能访问更前面的元素就可确保不重复，并且不会少解
            tmp.push_back(candidates[i]);
            cur += candidates[i];
            dfs(candidates, target, cur, i);
            cur -= candidates[i];
            tmp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates, target, 0, -1);
    return res;
}

int main(){
    vector<int> candidates{2, 3, 6, 7};
    combinationSum(candidates, 7);
    cout << 1 << endl;
}