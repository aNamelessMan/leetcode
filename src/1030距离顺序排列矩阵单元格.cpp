#include<bits/stdc++.h>
using namespace std;

// 执行用时：160 ms, 在所有 C++ 提交中击败了23.83% 的用户
// 内存消耗：29.2 MB, 在所有 C++ 提交中击败了16.62% 的用户
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    multimap<int, vector<int>>dis;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            dis.insert({abs(i - r0) + abs(j - c0), {i, j}});
        }
    }
    for(auto i = dis.begin(); i != dis.end(); i++)
        res.push_back(i->second);
    return res;
}

int main(){
    cout << 1 << endl;
}