#include <bits/stdc++.h>

using namespace std;

/**整数保序离散化
 *
 * 适用于当需要值域很大，但个数较少的一组数a作为下标时
 * 1. a[]中可能包含重复元素 -> 去重
 * 2. 如何算出a[n]离散化后的值 -> 即a[n]映射到n，排序加二分
 *
 * vector<int> vi;
 * sort(vi.begin(), vi.end());  // 排序
 * vi.erase(unique(vi.begin(), vi.end()), vi.end()); // 去重
 *
 * for(int i : vi) {
 *      二分找下标
 * }
 *
 */

bool check(const vector<int>& v, int idx, int target) {
    return v[idx] <= target;
}

int bs(const vector<int>& v, int l, int r, int target) {
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
    int n, m;
    cin >> n >> m;
    // 其实也可以不用map，用一个 离散化后的下标分别对应的 数组存值就行了
    // 但是存值的时候也会需要二分
    unordered_map<int, int> input;
    vector<int> idxs;
    int idx, v;
    for (int i = 0; i < n; i++) {
        cin >> idx >> v;
        input[idx] += v;
        idxs.push_back(idx);
    }
    vector<pair<int, int>> query;
    int l, r;
    // 得把 查询区间左右端也离散化，否则二分时不管是找 最后一个小于等于
    // 还是第一个大于等于 都会有问题，必须能找到等于
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        query.push_back(make_pair(l, r));
        idxs.push_back(l);
        idxs.push_back(r);
    }

    sort(idxs.begin(), idxs.end());
    idxs.erase(unique(idxs.begin(), idxs.end()), idxs.end());

    vector<int> prefix_sum;
    prefix_sum.push_back(0);
    for (int i = 0; i < idxs.size(); i++) {
        prefix_sum.push_back(prefix_sum[i] + input[idxs[i]]);
    }

    for (int i = 0; i < m; i++) {
        l = query[i].first;
        r = query[i].second;

        int r_idx = bs(idxs, 0, idxs.size() - 1, r);
        int l_idx = bs(idxs, 0, idxs.size() - 1, l);
        // 找出idxs中的下标 + 1 就是前缀和中对应下标
        cout << prefix_sum[r_idx + 1] - prefix_sum[l_idx + 1 - 1] << endl;
    }
}
