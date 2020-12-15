#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了37.55% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了10.39% 的用户
void fillin(vector<vector<char>>& board, int &cnt, vector<unordered_set<char>> &rows, vector<unordered_set<char>> &cols, vector<unordered_set<char>> &squs){
    if(cnt == 0)return;
    //找出限制最少的点
    int maxl = INT_MIN, minidx = -1;//记录限制最多也就是可能性最少的下标
    int i, j;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            int l = INT_MIN;
            if(board[i][j] == '.')l = (int)(rows[i].size() + cols[j].size() + squs[i / 3 + (j / 3) * 3].size());
            if(l > maxl){
                maxl = l;
                minidx = i * 9 + j;
            }
        }
    }
    int x = minidx / 9, y = minidx % 9;
    for(int c = '1'; c <= '9'; c++){
        if(!rows[x].count(c) && !cols[y].count(c) && !squs[x / 3 + (y / 3) * 3].count(c)){
            rows[x].insert(c);
            cols[y].insert(c);
            squs[x / 3 + (y / 3) * 3].insert(c);
            cnt--;
            board[x][y] = c;
            fillin(board, cnt, rows, cols, squs);
            if(cnt == 0)return;
            board[x][y] = '.';
            cnt++;
            squs[x / 3 + (y / 3) * 3].erase(c);
            cols[y].erase(c);
            rows[x].erase(c);
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    //记录每行每列每个3*3已经用过的值，和个数
    //这样可以计算出每个点还有哪些/多少数可用
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> squs(9);//计算每个点对应的方块很简单就是i / 3 + (j / 3) * 3
    int cnt = 0;//未填充的方格数
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.')cnt++;
            else{
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squs[i / 3 + (j / 3) * 3].insert(board[i][j]);
            }
        }
    }
    fillin(board, cnt, rows, cols, squs);
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},

        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},

        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    
    };
    solveSudoku(board);
    cout << 1 << endl;
}