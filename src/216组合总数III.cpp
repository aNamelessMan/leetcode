#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了52.99% 的用户
void dfs(vector<vector<int>> &res, vector<int> &t, int cur, int cursum, int k, int n){
    if(cursum == n && t.size() == k){
        res.push_back(t);
        return;
    }
    if(cursum > n || t.size() == k)return;
    for(int i = cur; i < 10; i++){
        cursum += i;
        t.push_back(i);
        dfs(res, t, i + 1, cursum, k, n);
        t.pop_back();
        cursum -= i;
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> t;
    vector<vector<int>> res;
    dfs(res, t, 1, 0, k, n);
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了80.86% 的用户
void fstdfs(int k, int s, vector<vector<int>> &res, vector<int> &tmp, int pre){//s是还需要加上多少,k是还可以加几个数
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
            fstdfs(k, s, res, tmp, i);
            tmp.pop_back();
        }
        s += i;
        k++;
    }

}

vector<vector<int>> fstcombinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tmp;

    fstdfs(k, n, res, tmp, 0);

    return res;
}

int main(){
    cout << 1 << endl;
}