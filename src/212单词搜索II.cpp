#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了89.88% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了53.57% 的用户
//直接搬用79题就行了
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

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string>  res;
    for(auto &str: words){
        if(exist(board, str))res.push_back(str);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}