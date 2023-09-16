#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> A, B;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        A.push_back(t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        B.push_back(t);
    }

    for (int i = 0, j = m - 1; i < n; i++) {
        // 对于每一个i，找出其是否可形成目标组合
        while (j >= 0 && A[i] + B[j] > x) j--;
        if (A[i] + B[j] == x) cout << i << " " << j << endl;
        // 因为上一次结束时 A[i] + B[j + 1] 一定> x
        // i右移，A[i + 1] + B[j + 1] > A[i] + B[j + 1] > x
        // 所以j只能左移
    }
}
