#include <bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了94.77% 的用户
// 内存消耗：12.7 MB, 在所有 C++ 提交中击败了82.12% 的用户
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(0 == m)return false;
    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while(i <= m - 1 && j >= 0){
        if(matrix[i][j] == target)return true;
        else if(matrix[i][j] > target)j--;
        else i++;
    }
    return false;
}

int main(){
    cout << "print sth." << endl;
}