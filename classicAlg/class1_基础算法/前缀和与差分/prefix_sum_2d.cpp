#include <bits/stdc++.h>

using namespace std;

/**
 *      1   2   3   4
 *  1   a1,1
 *  2
 *  3           a3,3
 *  4
 *
 * 横纵下标同样从1开始
 * 对于二维前缀和，S(i, j)表示 以a(1,1)与a(i,j)连线为对角线的矩形中所有值的和
 * eg. S(2, 2) = a(1,1) + a(1,2) + a(2,1) + a(2,2)
 * S(2, 3) = a(1,1) + a(1,2) + a(2,1) + a(2,2) + a(1, 3) + a(2, 3)
 *
 * 应用: 类似于前缀和数组
 * 可以求任意子矩阵的和
 * 画个方块图，很容易就能看出来
 * S(x2, y2) - S(x1 - 1, y2) - S(x2, y1 - 1) + S(x1 - 1, y1 - 1)
 *
 * S(i, j数组怎么求？
 * 一行行算，从左往右算
 * S(i, j) = S(i - 1, j) + S(i, j - 1) - S(i - 1, j - 1) + a(i, j)
 */

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        int t;
        for (int j = 1; j <= m; j++) {
            cin >> t;
            nums[i][j] = t;
        }
    }
    // 初始化二维前缀和矩阵
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] + nums[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum[x2][y2] + prefix_sum[x1 - 1][y1 - 1] -
                    prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1]
             << endl;
    }
}