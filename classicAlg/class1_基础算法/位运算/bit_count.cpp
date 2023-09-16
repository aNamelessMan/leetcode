#include <bits/stdc++.h>

using namespace std;

/**
 * 1. 查看x的二进制表示的第n位数
 * (x >> n) & 1
 * 2. lowbit(x) : 返回x的最后一位1的位置 eg.lowbit(1001000b) = 1000b
 * 是树状数组的基本操作
 * x & -x
 * 因为 -x = ~x + 1 x & -x = x & (~x + 1)
 * 模拟一下就知道正确性了
 *
 * 可以用于统计1的数量
 */

int main() {
    int n, t;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        t = nums[i];
        while (t) {
            cnt++;
            t -= (t & (-t));
            /**
             * 正常人的做法...
             * if(t % 2)cnt++;
             * t /= 2;
             */
        }
        cout << cnt << " ";
    }
    cout << endl;
}
