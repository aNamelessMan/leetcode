#include <bits/stdc++.h>

using namespace std;

/**
 * 存在数组 A = [a1, a2, ... , an]
 * 那么可定义前缀和数组 S = [s1, ... , sn], 其中 si = a1 + a2 + ... + ai
 * 注意下标从1开始，定义 s0 = 0, 便于处理边界，eg. 当求[1, n]的和时，
 * 可以统一为s(r) - s(l - 1) 即 s(n) - s(0) = s(n)
 *
 * Q1 : 如何求si？
 * A1 : s0 = 0; si = s(i - 1) + ai
 * Q2 : 有何作用？
 * A1 : 快速求出某段子区间的和，假设子区间为[l, r]，那么和为s(r) - s(l - 1)
 *
 * 当需要频繁求子区间和时和有用，因为每次遍历求和复杂度O(n)
 * 而使用前缀和，复杂度O(1)
 */
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> nums;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }

    vector<int> prefix_sum;
    prefix_sum.push_back(0);
    for (int i = 0; i < n; i++) {
        prefix_sum.push_back(prefix_sum[i] + nums[i]);
    }

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l;
        cin >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }
}
/**
输入样例：
5 3
2 1 3 6 4
1 2
1 3
2 4
输出样例：
3
6
10
*/
