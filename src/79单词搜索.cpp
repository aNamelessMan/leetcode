#include<bits/stdc++.h>
using namespace std;
// 执行用时：1256 ms, 在所有 C++ 提交中击败了5.09% 的用户
// 内存消耗：297.2 MB, 在所有 C++ 提交中击败了5.02% 的用户

//传参path不用引用会超时，用引用需要维护path
//对表格中的每个点dfs，注意不能重复，需要一个set保存经过的坐标
bool dfs(int i, int j, set<vector<int>> &path, int cur, int fin, vector<vector<char>>& board, string &word){
    if(cur == fin)return true;
    if(i < 0 || i == (int)board.size() || j < 0 || j == (int)board[0].size() || board[i][j] != word[cur] || path.find({i, j}) != path.end())return false;
    path.insert({i, j});
    cur++;
    //分成三行是为了维护path
    bool res =  (dfs(i + 1, j, path, cur, fin, board, word) || dfs(i, j + 1, path, cur, fin, board, word) || dfs(i, j - 1, path, cur, fin, board, word) || dfs(i - 1, j, path, cur, fin, board, word));
    path.erase(path.find({i, j}));
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < (int)board.size(); i++){
        for(int j = 0; j < (int)board[0].size(); j++){
            set<vector<int>> path;
            if(dfs(i, j, path, 0, word.size(), board, word))return true;
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}});
    cout << exist(board, "ABCCED") << endl;
}