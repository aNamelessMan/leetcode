#include <bits/stdc++.h>

using namespace std;

/**将有交集的区间合并为一个区间
 * 1. 按区间左端点排序
 * 2. 扫描一遍，扫描时维护一个当前区间的左右端点
 * 3. 扫描每个区间时：
 *      a. 遇到和当前区间有交集，则合并
 *      b. 无交集则设当前区间为该区间
 */

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    int l, r;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        input.push_back({l, r});
    }
    sort(input.begin(), input.end());
    int cur_l = input[0].first, cur_r = input[0].second;
    res++;
    for (int i = 1; i < input.size(); i++) {
        if (input[i].first > cur_r) {
            cur_l = input[i].first;
            cur_r = input[i].second;
            res++;
        } else {
            cur_r = max(cur_r, input[i].second);
        }
    }
    cout << res << endl;
}
