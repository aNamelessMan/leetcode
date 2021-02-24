#include <bits/stdc++.h>
using namespace std;

// 执行用时：112 ms, 在所有 C++ 提交中击败了59.27% 的用户
// 内存消耗：53.6 MB, 在所有 C++ 提交中击败了53.23% 的用户
//dfs
bool dfs(int i, int j, unordered_set<int> &s, int cur, int ws, string& word, vector<vector<char>>& board, int m, int n){
    if(cur == ws)return true;
    //其实可以简化代码，无论是否越界都递归，然后在函数开头判断是否越界，越界即返回false
    if(i > 0 && !s.count((i - 1) * n + j) && word[cur] == board[i - 1][j]){
        s.insert((i - 1) * n + j);
        if(dfs(i - 1, j, s, cur + 1, ws, word, board, m, n))return true;
        s.erase((i - 1) * n + j);
    }
    if(i < m - 1 && !s.count((i + 1) * n + j) && word[cur] == board[i + 1][j]){
        s.insert((i + 1) * n + j);
        if(dfs(i + 1, j, s, cur + 1, ws, word, board, m, n))return true;
        s.erase((i + 1) * n + j);
    }
    if(j > 0 && !s.count(i * n + j - 1) && word[cur] == board[i][j - 1]){
        s.insert(i * n + j - 1);
        if(dfs(i, j - 1, s, cur + 1, ws, word, board, m, n))return true;
        s.erase(i * n + j - 1);
    }
    if(j < n - 1 && !s.count(i * n + j + 1) && word[cur] == board[i][j + 1]){
        s.insert(i * n + j + 1);
        if(dfs(i, j + 1, s, cur + 1, ws, word, board, m, n))return true;
        s.erase(i * n + j + 1);
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int ws = word.size();
    if(0 == ws)return true;
    int m = board.size();
    if(0 == m)return false;
    int n = board[0].size();

    unordered_set<int> s;//当前已经过的节点
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == word[0]){
                s.insert(i * n + j);//注意要乘上的是列数n而不是行数m
                if(dfs(i, j, s, 1, ws, word, board, m, n))return true;
                s.erase(i * n + j);
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board({{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}});
    cout << exist(board, "ABCESEEEFS") << endl;
    cout << "print sth." << endl;
}