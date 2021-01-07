#include<bits/stdc++.h>
using namespace std;

// 执行用时：100 ms, 在所有 C++ 提交中击败了7.22% 的用户
// 内存消耗：14.5 MB, 在所有 C++ 提交中击败了6.78% 的用户
void bfs(vector<vector<int>>& isConnected, int i, vector<bool> &discovered, int n){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        discovered[t] = true;
        for(int j = 0; j < n; j++){
            if(isConnected[t][j] && !discovered[j]){
                q.push(j);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    //求无向图的联通分量的个数  BFS
    //用一个数组记录是否已经经过即可
    int n = isConnected.size();
    vector<bool> discovered(n, false);

    int c = 0;
    for(int i = 0; i < n; i++){
        if(discovered[i])continue;
        c++;
        bfs(isConnected, i, discovered, n);
    }

    return c;
}

int main(){
    cout << 1 << endl;
}