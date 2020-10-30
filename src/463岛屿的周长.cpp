#include<bits/stdc++.h>
using namespace std;
// 执行用时：228 ms, 在所有 C++ 提交中击败了25.30% 的用户
// 内存消耗：94.2 MB, 在所有 C++ 提交中击败了10.23% 的用户
int islandPerimeter(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty())return 0;
    int res = 0, m = grid.size(), n = grid[0].size();
    for(int i = 0 ; i < m ; i++){//观察上下左右是否为水或是边界
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j]){
                if(i + 1 == m || !grid[i + 1][j])res++;
                if(j + 1 == n || !grid[i][j + 1])res++;
                if(i - 1 < 0 || !grid[i - 1][j])res++;
                if(j - 1 < 0 || !grid[i][j - 1])res++;
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}