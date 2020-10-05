#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了5.04% 的用户
map<string, map<string, double> > graph;//加权有向图
double helper(string up, string down, unordered_set<string>& visited) {
    if (graph[up].count(down)) return graph[up][down];
    for (auto a : graph[up]) {
        if (visited.count(a.first)) continue;
        visited.insert(a.first);
        double t = helper(a.first, down, visited);
        if (t > 0.0) return t * a.second;
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> res;
    //建图
    for(unsigned i = 0; i < equations.size(); i++){
        graph[equations[i][0]][equations[i][1]] = values[i];
        graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        graph[equations[i][0]][equations[i][0]] = 1;
        graph[equations[i][1]][equations[i][1]] = 1;
    } 
    //接下来对每个求解式dfs求解即可
    for (auto query : queries) {
        unordered_set<string> visited;
        double t = helper(query[0], query[1], visited);
        res.push_back((t > 0.0) ? t : -1);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}