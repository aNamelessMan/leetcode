#include <bits/stdc++.h>

using namespace std;

/*
到每一行每个点的最长路径一定是从上一行的左边或右边到当前点
因此比较取 上一行 左侧点prev[j - 1] 和 右侧点prev[j] 中较大值加上当前点的权重
就是到当前点的最长路径
如此迭代到最后一行，取最后一行所有点中的最长路径即可
*/

int main() {
    vector<int> prev;
    vector<int> cur;
    int n, t;
    cin >> n;
    cin >> t;
    prev.push_back(t);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> t;
            if (j == 0) {
                cur.push_back(prev[j] + t);
            } else if (j == i) {
                cur.push_back(prev[j - 1] + t);
            } else {
                cur.push_back(max(prev[j], prev[j - 1]) + t);
            }
        }
        prev = cur;
        cur.clear();
    }
    cout << *max_element(prev.begin(), prev.end()) << endl;
}
