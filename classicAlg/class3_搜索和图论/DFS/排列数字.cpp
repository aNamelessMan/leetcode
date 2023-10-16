#include <bits/stdc++.h>

using namespace std;

void dfs(int n, vector<int>& path, vector<int>& processed) {
    if (path.size() == n) {
        for (const auto& no : path) {
            cout << no << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (processed[i]) {
            continue;
        } else {
            path.push_back(i);
            processed[i] = 1;
            dfs(n, path, processed);
            processed[i] = 0;
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> path;
    vector<int> processed(n + 1, 0);
    dfs(n, path, processed);
}
