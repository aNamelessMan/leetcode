#include<bits/stdc++.h>
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了11.69% 的用户
// 内存消耗：21.9 MB, 在所有 C++ 提交中击败了5.01% 的用户
bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> row(9, unordered_set<char>());
    vector<unordered_set<char>> column(9, unordered_set<char>());
    vector<vector<unordered_set<char>>> block(3, vector<unordered_set<char>>(3, unordered_set<char>()));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.')continue;
            if(row[i].count(board[i][j]) || column[j].count(board[i][j]) || block[i / 3][j / 3].count(board[i][j]))return false;
            row[i].insert(board[i][j]);
            column[j].insert(board[i][j]);
            block[i / 3][j / 3].insert(board[i][j]);
        }
    }
    return true;
}

int main(){
    cout << 1 << endl;
}