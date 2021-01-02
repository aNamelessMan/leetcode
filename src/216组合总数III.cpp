#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了80.86% 的用户
void dfs(int k, int s, vector<vector<int>> &res, vector<int> &tmp, int pre){//s是还需要加上多少,k是还可以加几个数
    if(k == 1){
        if(s > pre){
            tmp.push_back(s);
            res.push_back(tmp);
            tmp.pop_back();
        }
        return;
    }

    for(int i = pre + 1; i <= 9; i++){
        s -= i;
        k--;
        if(s < k || s > k * 9){
            s += i;
            k++;
            continue;
        }else{
            tmp.push_back(i);
            dfs(k, s, res, tmp, i);
            tmp.pop_back();
        }
        s += i;
        k++;
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tmp;

    dfs(k, n, res, tmp, 0);

    return res;
}

int main(){
    cout << 1 << endl;
}