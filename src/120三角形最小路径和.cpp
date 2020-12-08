#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了90.83% 的用户
// 内存消耗：8.5 MB, 在所有 C++ 提交中击败了37.07% 的用户
int minimumTotal(vector<vector<int>>& triangle) {
    int res = INT_MAX, n = triangle.size();

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
            else if(j == i)triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            else triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
        }
    }

    auto iter = min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    return *iter;
}

// 42 / 43 个通过测试用例   TLE
void dfs(vector<vector<int>>& triangle, int &res, int curi, int curj, int n, int p){
    if(curi == n){
        res = min(res, p);
        return;
    }
    dfs(triangle, res, curi + 1, curj, n, p + triangle[curi][curj]);
    dfs(triangle, res, curi + 1, curj + 1, n, p + triangle[curi][curj]);
}

int BFminimumTotal(vector<vector<int>>& triangle) {
    int res = INT_MAX, n = triangle.size();
    dfs(triangle, res, 0, 0, n, 0);
    return res;
}

int main(){
    cout << 1 << endl;
}