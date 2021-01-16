#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了97.62% 的用户
//就是简单的暴力解法，本来以为会超时都懒得写的...难怪是中等题...
void count(vector<vector<int>>& board, int i, int j, int m, int n){
    /*
    [i,j]
    [i - 1, j - 1]    [i - 1, j]  [i - 1, j + 1]
    [i, j - 1]        [i, j]      [i, j + 1]
    [i + 1, j - 1]    [i + 1, j]  [i + 1, j + 1]
    */
    if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] > 9)board[i][j]++;
    if(i - 1 >= 0 && board[i - 1][j] > 9)board[i][j]++;
    if(i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] > 9)board[i][j]++;
    if(j - 1 >= 0 && board[i][j - 1] > 9)board[i][j]++;
    if(j + 1 < n && board[i][j + 1] > 9)board[i][j]++;
    if(i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1] > 9)board[i][j]++;
    if(i + 1 < m && board[i + 1][j] > 9)board[i][j]++;
    if(i + 1 < m && j + 1 < n && board[i + 1][j + 1] > 9)board[i][j]++;
}

void gameOfLife(vector<vector<int>>& board) {
    /* 
    < 2  必死
    = 2  保持
    = 3  必活
    > 3  必死
    */
    //可以第一遍遍历用十位表示原状态，个位表示周围活细胞个数
    //第二遍遍历再更新
    int m = board.size();
    if(m == 0)return;
    int n = board[0].size();
    if(n == 0)return;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            board[i][j] *= 10;
        }
    }//现在状态为10/00  因此大于9则为活
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            count(board, i, j, m, n);
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int c = board[i][j] % 10;
            if(c == 2)board[i][j] /= 10;
            else if(c == 3)board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}

int main(){
    cout << "print something." << endl;
}