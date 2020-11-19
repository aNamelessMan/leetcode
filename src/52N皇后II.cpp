#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了35.90% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了28.13% 的用户
//把上一题的输出改一下就行了，比上一题一模一样还更简单..
void dfs(vector<bool> &cols, int &r, int cur, int n, int i, vector<vector<int>> &points){
    if(cur == n){
        r++;
    }
    for(int j = 0; j < n; j++){
        if(cols[j])continue;
        bool can = true;
        for(auto &p:points){//判断是否在同一斜线上
            if(abs(p[0] - i) == abs(p[1] - j)){
                can = false;
                break;
            }
        }
        if(can){
            points.push_back({i, j});
            cols[j] = true;
            dfs(cols, r, cur + 1, n, i + 1, points);
            cols[j] = false;
            points.pop_back();
        }
    }
}

int totalNQueens(int n) {
//约束条件  行列都不能相同
//不在同一直线  横纵坐标差的绝对值不能相同
    vector<bool> cols(n, false);
    vector<vector<int>> points;
    int r = 0;
    dfs(cols, r, 0, n, 0, points);
    return r;
}

int main(){
    cout << 1 << endl;
}