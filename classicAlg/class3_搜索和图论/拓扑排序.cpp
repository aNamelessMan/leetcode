#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, src, dst;
    cin >> n >> m;
    // 建图
    unordered_set<int> points;
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> src >> dst;
        points.insert(src);
        points.insert(dst);
        edges[src].push_back(dst);
        if (indegree.find(dst) == indegree.end()) {
            indegree[dst] = 1;
        } else {
            indegree[dst]++;
        }
    }
    // bfs拓扑排序
    vector<int> res;
    queue<int> q;
    int cnt = 0;
    for (const auto& p : points) {
        if (indegree.find(p) == indegree.end()) {
            q.push(p);
            cnt++;
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        res.push_back(t);
        for (const auto& next : edges[t]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
                cnt++;
            }
        }
    }
    if (cnt == n) {
        for (const auto& p : res) {
            cout << p << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
