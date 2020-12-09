#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了72.60% 的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了23.47% 的用户
void solve(vector<vector<char>>& board) {
    unordered_set<int> stillo;//点在set里表示为i * n + j
    int m = board.size();//行数
    if(m == 0)return;
    int n = board[0].size();//列数
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(board[0][i] == 'O')q.push(i);
        if(board[m - 1][i] == 'O')q.push((m - 1) * n + i);
    }
    for(int j = 1; j < m - 1; j++){
        if(board[j][0] == 'O')q.push(j * n);
        if(board[j][n - 1] == 'O')q.push(j * n + n - 1);
    }

    while(!q.empty()){
        auto point = q.front();
        q.pop();
        if(stillo.count(point))continue;
        stillo.insert(point);
        int j = point % n, i = (point - j) / n;
        if(j - 1 >= 0 && board[i][j - 1] == 'O')q.push(i * n + j - 1);
        if(j + 1 < n && board[i][j + 1] == 'O')q.push(i * n + j + 1);
        if(i - 1 >= 0 && board[i - 1][j] == 'O')q.push((i - 1) * n + j);
        if(i + 1 < m && board[i + 1][j] == 'O')q.push((i + 1) * n + j);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O' && !stillo.count(i * n + j))
                board[i][j] = 'X';
        }
    }
}

int main(){
    cout << 1 << endl;
}