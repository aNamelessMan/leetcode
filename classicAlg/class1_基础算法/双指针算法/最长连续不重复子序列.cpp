#include <bits/stdc++.h>

using namespace std;

/**
 * 双指针的核心：
 * 两个指针共有 n^2 种组合
 * 通过应用性质，只枚举O(n)种状态，将暴力算法的O(n^2)优化到O(n)
 * 即将
 * for(int i = 0; i < n; i==){
 *    for(int j = 0; j < n; j++){
 *        ...
 *    }
 * }
 * 优化成类似于以下形式
 * for(int i = 0, j = 0; i < n; i++){
 *     while(j < i && check(i, j))j++;
 *     ...
 * }
 *
 * 写题时可以先想暴力解法，找出单调性，优化到O(n)
 */
class YxcSolution {
public:
    // 判断区间中是否有重复值，有则返回true，无则返回false
    static bool check(int i, unordered_map<int, int> &ch_set,
                      vector<int> &input) {
        return ch_set[input[i]] > 1;
    }
    int lengthOfLongestSubstring(vector<int> input) {
        unordered_map<int, int> ch_set;
        int res = 0, n = input.size();
        // 枚举i 右边界
        // 对于每个i，找到其最左边界j
        for (int i = 0, j = 0; i < n; i++) {
            // 将右边界加入集合
            ch_set[input[i]]++;
            // 收缩左边界，直到满足无重复，即为最左边界
            // Note：左边界不可能向左扩张，因为如果左右边界能同时扩张，说明上一轮求的最左边界肯定是错的
            // 所以如果我们假设上一轮最右边界求的是对的，那么左边界只能向左
            while (j <= i && check(i, ch_set, input)) {
                ch_set[input[j]]--;
                j++;
            }
            res = max(res, i - j - 1);
        }
        return res;
    }
};

class MySolution {
public:
    int lengthOfLongestSubstring(vector<int> input) {
        unordered_set<int> ch_set;
        int res = 0;
        int i = 0, j = 0, n = input.size();
        while (1) {
            // 对每一个i(左边界)，找到离它最远的右边界j
            while (j < n && ch_set.find(input[j]) == ch_set.end()) {
                ch_set.insert(input[j]);
                j++;
            }
            res = max(res, j - i);
            if (j == n) {
                return res;
            }
            // 在排除导致重复的元素之前，右边界不可能前进
            // 因此让i前进直到排出重复元素
            // 且此时区间长度一直在缩小，无需比较res
            while (input[i] != input[j]) {
                ch_set.erase(input[i]);
                i++;
            }
            ch_set.erase(input[i]);
            i++;
        }
        return res;
    }
};

int main() {
    int n;
    vector<int> vec_int;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        vec_int.push_back(t);
    }
    // vector<int> vec_int{
    //     16, 39, 7,  29, 34, 14, 36, 16, 37, 38, 6,  3,  11, 3,  39, 9,  25,
    //     20, 14, 26, 4,  23, 17, 30, 14, 25, 24, 16, 30, 4,  35, 13, 30, 13,
    //     30, 37, 0,  16, 21, 5,  28, 9,  24, 5,  28, 3,  21, 16, 28, 23, 29,
    //     23, 23, 22, 13, 15, 32, 10, 39, 16, 4,  8,  6,  38, 33, 12, 29, 38,
    //     39, 33, 16, 30, 35, 39, 36, 29, 7,  39, 2,  0,  4,  14, 34, 37, 30,
    //     21, 2,  12, 39, 33, 13, 17, 1,  39, 23, 40, 37, 28, 30, 22};
    MySolution s;
    cout << s.lengthOfLongestSubstring(vec_int) << endl;
}