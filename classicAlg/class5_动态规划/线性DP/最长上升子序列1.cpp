// 即LIS，DP求解，本文件是O(n^2)的解法，O(nlog n)的解法在LIS2文件
// leetcode300
// 注意与 最长连续序列 leetcode128区分

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> a;
    vector<int> max_length;
    for (int i = 0; i < n; i++) {
        cin >> t;
        int r = 1;
        int l = a.size();
        for (int j = 0; j < l; j++) {
            if (a[j] < t) {
                r = max(r, max_length[j] + 1);
            }
        }

        a.push_back(t);
        max_length.push_back(r);
    }

    cout << *max_element(max_length.begin(), max_length.end()) << endl;
}
