#include<bits/stdc++.h>
using namespace std;

//无向图，因为都是不同元素一定无重边
//如果节点度数为1一定是边界
vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, int> deg;
    unordered_map<int, vector<int>> adj;
    vector<int> res;
    for(auto &v:adjacentPairs){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
        deg[v[0]]++;
        deg[v[1]]++;
    }
    int start;
    for(auto iter = deg.begin(); iter != deg.end(); iter++){
        if(iter->second == 1){
            start = iter->first;
            break;
        }
    }
    res.push_back(start);
    int next = adj[start][0];
    res.push_back(next);
    int pre = start;
    while(adj[next].size() > 1){
        int t = next;
        next = adj[next][0] == pre?adj[next][1]:adj[next][0];
        pre = t;
        res.push_back(next);
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}