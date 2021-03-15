#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了68.88% 的用户
// 内存消耗：13.4 MB, 在所有 C++ 提交中击败了32.02% 的用户
//bfs的解法 也就是拓扑排序，当没有入度为0的课程时，返回是否所有课程已上完  简单快速    
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indeg(numCourses);//记录入度
    unordered_map<int, vector<int>> m;
    for(auto &p:prerequisites){
        indeg[p[0]]++;
        m[p[1]].push_back(p[0]);
    }
    int cnt = 0;
    queue<int> q;
    for(int i = 0; i < numCourses; i++){
        if(indeg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        cnt++;
        for(int i:m[t]){
            indeg[i]--;
            if(indeg[i] == 0)q.push(i);
        }
    }
    return cnt == numCourses;
}

// set<int> processed;
// set<int> path;
// 执行用时：228 ms, 在所有 C++ 提交中击败了5.04% 的用户
// 内存消耗：11.5 MB, 在所有 C++ 提交中击败了86.55%
//用vector和数组时间差不多，用set是它们的两倍多
//set尽量用 bool/int 的 数组/vector 代替
bool dfs(int node, vector<vector<int>>& prerequisites, int *processed, int *path){
    //path.insert(node);
    path[node] = 1;
    for(auto &p:prerequisites){
        if(p[0] != node || processed[p[1]])continue;
        else{
            if(path[p[1]])return false;
            if(!dfs(p[1], prerequisites, processed, path))return false;
        }
    }
    //processed.insert(node);
    processed[node] = 1;
    //path.erase(node);
    path[node] = 0;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//也就是判断有没有环
    int processed[numCourses];
    int path[numCourses];
    for(int i = 0; i < numCourses; i++){
        processed[i] = 0;
        path[i] = 0;
    }
    // vector<int> processed(numCourses, 0);
    // vector<int> path(numCourses, 0);
    for(int i = 0; i < numCourses; i++){
        if(!dfs(i, prerequisites, processed, path))return false;
        //processed.insert(i);
        processed[i] = 1;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}