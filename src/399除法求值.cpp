#include<bits/stdc++.h>
#include "../dataStruc/vecOps.hpp"
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

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了34.34% 的用户
/*
2021.1.6二刷自己写的解
这个解其实有点小问题，但是测试用例没找到，
存等式结果的unorde_map直接拿第一个字符串和第二个字符串拼接作为键值，这样有可能两个不同的等式键值是一样的，比如["a", "bc"] 和 ["ab", "c"]
*/
double dfs(string &cur, string &target, double c, unordered_map<string, vector<string>> &m, unordered_map<string, double> &equ, unordered_set<string> &path){
    if(cur == target)return c;
    for(string &next:m[cur]){
        if(path.count(next))continue;
        path.insert(next);
        c *= equ[cur + next];
        double r = dfs(next, target, c, m, equ, path);
        if(r != -1)return r;
        c /= equ[cur + next];
        path.erase(next);
    }
    return -1;
}

vector<double> secondcalcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> res;
    //建图
    unordered_map<string, vector<string>> m;//无向图
    unordered_map<string, double> equ;//已知等式的值
    int n = equations.size();
    for(int i = 0; i < n; i++){
        m[equations[i][0]].push_back(equations[i][1]);
        m[equations[i][1]].push_back(equations[i][0]);
        equ[equations[i][0] + equations[i][1]] = values[i];
        equ[equations[i][1] + equations[i][0]] = 1 / values[i];
    }
    //对每个查询进行dfs
    for(auto &q:queries){
        unordered_set<string> path;//存储经过的节点，防止环路
        if(!m.count(q[0])){
            res.push_back(-1);
        }else{
            res.push_back(dfs(q[0], q[1], 1, m, equ, path));
        }
    }
    return res;
}

int main(){
    vector<vector<string>> equ = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> val = {1.5, 2.5, 5.0};
    vector<vector<string>> que = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}};
    auto res = secondcalcEquation(equ, val, que);
    printVector(res);
}