#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        b.push_back(t);
    }

    // 遍历子序列每个值，寻找父序列中的对应元素
    for (int i = 0, j = 0; i < n; i++, j++) {
        while (j < m && b[j] != a[i]) j++;
        if (j == m) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
