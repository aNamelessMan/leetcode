#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了99.31% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了13.78% 的用户
//相比下面的就换了个数据结构快了好几倍  二维数组递归传递比较麻烦应该会更快
void addin(int i, int j, vector<vector<char>>& grid, int m, int n, vector<vector<int>>& points){
    //{i - 1, j}    {i + 1, j}  {i, j - 1}  {i, j+ 1}
    points[i][j] = 1;
    if(i + 1 < m && grid[i + 1][j] == '1' && !points[i + 1][j]) addin(i + 1, j, grid, m, n, points);
    if(j + 1 < n && grid[i][j + 1] == '1' && !points[i][j + 1]) addin(i, j + 1, grid, m, n, points);
    if(i - 1 > -1 && grid[i - 1][j] == '1' && !points[i - 1][j])addin(i - 1, j, grid, m, n, points);
    if(j - 1 > -1 && grid[i][j - 1] == '1' && !points[i][j - 1])addin(i, j - 1, grid, m, n, points);
}

int numIslands(vector<vector<char>>& grid) {
//连通问题
//每遍历一个点，查询它的上下左右是否有一，有的话是否已经遍历过了，没有则递归地将所有相邻1添加进去
    if(grid.empty() || grid[0].empty())return 0;
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> points(m, vector<int>(n, 0));
    // int points[m][n];
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         points[i][j] = 0;
    //     }
    // }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1' && !points[i][j]){
                addin(i, j, grid, m, n, points);
                res++;
            }
        }
    }
    return res;
}

// 执行用时：96 ms, 在所有 C++ 提交中击败了5.69% 的用户
// 内存消耗：16.4 MB, 在所有 C++ 提交中击败了5.00% 的用户
set<pair<int, int>> points;

void slowaddin(int i, int j, vector<vector<char>>& grid, int m, int n){
    //{i - 1, j}    {i + 1, j}  {i, j - 1}  {i, j+ 1}
    points.insert(make_pair(i, j));
    if(i + 1 < m && grid[i + 1][j] == '1' && !points.count(make_pair(i+1, j))) slowaddin(i + 1, j, grid, m, n);
    if(j + 1 < n && grid[i][j + 1] == '1' && !points.count(make_pair(i, j+1))) slowaddin(i, j + 1, grid, m, n);
    if(i - 1 > -1 && grid[i - 1][j] == '1' && !points.count(make_pair(i-1, j)))slowaddin(i - 1, j, grid, m, n);
    if(j - 1 > -1 && grid[i][j - 1] == '1' && !points.count(make_pair(i, j-1)))slowaddin(i, j - 1, grid, m, n);
}

int slownumIslands(vector<vector<char>>& grid) {
//连通问题
//每遍历一个点，查询它的上下左右是否有一，有的话是否已经遍历过了，没有则递归地将所有相邻1添加进去
    if(grid.empty() || grid[0].empty())return 0;
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1' && !points.count(make_pair(i, j))){//注意审题vector里是char不能直接判断是不是0
                slowaddin(i, j, grid, m, n);
                res++;
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}