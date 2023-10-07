#include <bits/stdc++.h>
using namespace std;

// 不需要dfs判断是否有环，计数已遍历课程，根据计数决定返回即可
class Solution231008 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> res;
        int cnt = 0;
        vector<int> indeg(numCourses, 0);  // 记录每个节点的入度

        unordered_map<int, vector<int>> m;  // 建立邻接矩阵
        for (auto &e : prerequisites) {
            indeg[e[0]]++;
            m[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int i : m[t]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    q.push(i);
                    cnt++;
                }
            }
        }
        return cnt == numCourses ? res : vector<int>();
    }
};

bool dfs(int node, vector<vector<int>> &prerequisites, int *processed,
         int *path) {
    path[node] = 1;
    for (auto &p : prerequisites) {
        if (p[0] != node || processed[p[1]])
            continue;
        else {
            if (path[p[1]]) return false;
            if (!dfs(p[1], prerequisites, processed, path)) return false;
        }
    }
    processed[node] = 1;
    path[node] = 0;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // 也就是判断有没有环
    int processed[numCourses];
    int path[numCourses];
    for (int i = 0; i < numCourses; i++) {
        processed[i] = 0;
        path[i] = 0;
    }
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, prerequisites, processed, path)) return false;
        processed[i] = 1;
    }
    return true;
}
// 执行用时：52 ms, 在所有 C++ 提交中击败了39.05% 的用户
// 内存消耗：13.5 MB, 在所有 C++ 提交中击败了86.70% 的用户
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> res;
    if (!canFinish(numCourses, prerequisites))
        return res;  // 借用207题的代码来判断有没有环，是否有可行的课程表
    // 接下来用bfs拓扑排序即可
    /*
    思路就是，先找出入度为0的点，加入队列
    学习队首，将队首的后续课程入度减一，判断入度是否为0，是则加入队列

    所以关键是想到
        入度代表未完成的先决条件
        然后知道如何用bfs拓扑排序
    就很简单了
    */
    vector<int> indeg(numCourses, 0);  // 记录每个节点的入度

    unordered_map<int, vector<int>> m;  // 建立邻接矩阵
    for (auto &e : prerequisites) {
        indeg[e[0]]++;
        m[e[1]].push_back(e[0]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        res.push_back(t);
        for (int i : m[t]) {
            indeg[i]--;
            if (indeg[i] == 0) q.push(i);
        }
    }
    return res;
}

int main() { cout << "print something." << endl; }