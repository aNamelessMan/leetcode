#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了38.60% 的用户
//旋转从里往外数第几层
void rot(vector<vector<int>>& matrix, int n){
    //第n层的边长为1 + 2 * n
    int s = matrix[0].size();
    //注意根据边长奇偶选择边界
    int b;
    if(s % 2)b = s/2+n;
    else b = s/2+n-1;
    for(int i = s / 2 - n, j = s / 2 - n; j <  b; j++){
        //四个数分别为(i,j)(n - j, i)(n - i, n - j)(j, n - i)
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[s-1 - j][i];
        matrix[s-1 - j][i] = matrix[s-1 - i][s-1 - j];
        matrix[s-1 - i][s-1 - j] = matrix[j][s-1 - i];
        matrix[j][s-1 - i] = tmp;
    }
}

void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty())return;
    int s = matrix[0].size();
    for(int i = 1; i <= s/2; i++){
        rot(matrix, i);
    }
    return;
}

int main(){
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(matrix);
    cout << 1 << endl;
}