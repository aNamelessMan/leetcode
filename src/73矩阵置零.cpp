#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了92.50% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了43.39% 的用户
//原地算法，可以先想简单的做法，然后用传入的参数本身来存储所需的信息
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m == 0)return;
    int n = matrix[0].size();
    //判断首行首列是否要清零
    bool clear1stRow = false, clear1stCol = false;
    for(int i = 0; i < n; i++){
        if(matrix[0][i] == 0){
            clear1stRow = true;
            break;
        }
    }
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
            clear1stCol = true;
            break;
        }
    }
    //用首行首列来存储是否要清零
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    //除首行首列的处理
    for(int i = 1; i < m; i++){
        if(matrix[i][0] == 0){
            for(int j = 1; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(matrix[0][i] == 0){
            for(int j = 1; j < m; j++){
                matrix[j][i] = 0;
            }
        }
    }
    //处理首行首列
    if(clear1stRow){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }
    if(clear1stCol){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    cout << 1 << endl;
}