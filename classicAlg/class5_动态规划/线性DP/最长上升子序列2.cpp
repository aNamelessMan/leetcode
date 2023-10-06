#include <bits/stdc++.h>

using namespace std;

// 性质是v[i] < target
bool check(const vector<int> &v, int mid, int target) {
    return v[mid] < target;
}

// 找到最后一个值小于target的下标
int bs(const vector<int> &v, int l, int r, int target) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(v, mid, target)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int n, t;
    cin >> n;
    vector<int> a;
    // 只需记录每个长度子序列的最小末尾值即可用于后续判断是否可形成更长上升子序列
    vector<int> max_length(n + 1, INT_MAX);
    /* max_length[i]表示长度为i的所有子序列的最小末尾值，INT_MAX表示无该长度的子序列
    max_length一定是单调递增的（
        否则会有矛盾，若max_length[i - 1] >= max_length[i]，
        那么对应max_length[i]）这个子序列中的倒数第二个数
        一定小于max_length[i- 1]对应子序列的末尾数，
        那么则说明max_length[i - 1]记录有误
    所以可以通过二分找到最后一个小于当前值的i，尝试更新max_length[i + 1]
    */
    for (int i = 0; i < n; i++) {
        cin >> t;
        int idx = bs(max_length, 1, max_length.size() - 1, t);
        if (max_length[idx] >= t) {  // 找不到更小值
            max_length[1] = min(max_length[1], t);
        } else {
            max_length[idx + 1] = min(max_length[idx + 1], t);
        }
    }
    int res = 1;
    for (int i = max_length.size() - 1; i >= 0; i--) {
        if (max_length[i] != INT_MAX) {
            res = i;
            break;
        }
    }
    cout << res << endl;
}