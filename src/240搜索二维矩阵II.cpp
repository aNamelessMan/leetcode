#include<bits/stdc++.h>
using namespace std;
// 执行用时：144 ms, 在所有 C++ 提交中击败了64.77% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了5.26% 的用户
//很经典的题了，好久之前看到过，就没想直接写了
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while(i < m && j > -1){
        if(matrix[i][j] == target)return true;
        else if(matrix[i][j] < target)i++;
        else    j--;
    }
    return false;
}

int main(){
    cout << 1 << endl;
}