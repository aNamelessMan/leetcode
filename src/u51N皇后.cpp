#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了63.91% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了37.40% 的用户
//递归地过程就是按行遍历的过程，因此递归内部不用再写行的for循环，也无需判断行是否重复
//结束条件是n行都已经放置了一个
void dfs(vector<bool> &cols, vector<string> &res, vector<vector<string>> &r, int cur, int n, int i, vector<vector<int>> &points){
    if(cur == n){
        r.push_back(res);
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
            res[i][j] = 'Q';
            cols[j] = true;
            dfs(cols, res, r, cur + 1, n, i + 1, points);
            cols[j] = false;
            res[i][j] = '.';
            points.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
//约束条件  行列都不能相同
//不在同一直线  横纵坐标差的绝对值不能相同
    vector<bool> cols(n, false);
    vector<string> res(n, string(n, '.'));
    vector<vector<int>> points;
    vector<vector<string>> r;
    dfs(cols, res, r, 0, n, 0, points);
    return r;
}

int main(){
    solveNQueens(4);
    //cout << 1 << endl;
}