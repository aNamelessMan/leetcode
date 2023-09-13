#include <bits/stdc++.h>

using namespace std;

/**
 * 差分是前缀和的逆运算
 * 即 存在数组 A = [a1, a2, ... , an]
 * 若A数组是B数组的前缀和，那么B是A的差分数组
 *
 * ai = b1 + b2 + ... + bi;
 * b1 = a1
 * b(n) = a(n) - a(n - 1)
 *
 * 用处（性质） :
 * O(n)的时间求出原数组，
 * 可以用O(1)的时间将原数组的某段区间加上某个值，而如果采用遍历某段区间复杂度会是O(n)
 * 即b[l] + C, b[r + 1] - C
 * 这样根据b还原出的a数组的区间[l, r]就都会加上某个值
 */
// #797 差分
int main() {
    int n, m;
    cin >> n >> m;
    int t;
    vector<int> res(n + 2, 0);
    // 读取原数组,将其视为初始值都为0的数组a，依次进行区间[i, i]加上输入值的变换
    // 对初始值都为0的数组b进行对应操作，即可获得初始的差分数组
    for (int i = 1; i <= n; i++) {
        cin >> t;
        res[i] += t;
        res[i + 1] -= t;
    }
    // 进行题目指定的操作序列
    int l, r, c;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r >> c;
        res[l] += c;
        res[r + 1] -= c;
    }
    // 再反求出res的前缀和就是结果
    for (int i = 1; i <= n; i++) {
        res[i] = res[i] + res[i - 1];
        cout << res[i] << " ";
    }
    cout << endl;
}
