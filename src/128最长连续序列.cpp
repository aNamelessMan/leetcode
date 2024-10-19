#include <bits/stdc++.h>
using namespace std;

class Solution241015 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (const auto& num : nums) {
            nums_set.insert(num);
        }
        int res = 0;
        for (const auto num : nums_set) {
            // 不是连续序列的开头值不用管
            if (nums_set.find(num - 1) != nums_set.end()) {
                continue;
            } else {
                int iter = num;
                while (nums_set.find(iter) != nums_set.end()) {
                    iter++;
                }
                res = max(res, iter - num);
            }
        }
        return res;
    }
};

// 并查集的做法 O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const auto& num : nums) {
            num_set.insert(num);
            parent[num] = num;
            cnt[num] = 1;
        }
        for (const auto& num : num_set) {
            if (num_set.find(num + 1) != num_set.end()) {
                merge(num, num + 1);
            }
        }
        int res = 0;
        for (const auto& num : num_set) {
            res = max(res, cnt[num]);
        }
        return res;
    }

private:
    // 找祖先节点
    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    void merge(int a, int b) {
        // 注意更新计数一定要在更新parent前面!!!!
        if (find(a) != find(b)) {
            cnt[find(b)] += cnt[find(a)];
        }
        parent[find(a)] = find(b);
    }
    // UnionFind
    unordered_map<int, int> parent;
    unordered_map<int, int> cnt;
};

// 简单的O(n)做法
class SimpleSolution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> num_set;
        // 去重
        for (const auto& num : nums) {
            num_set.insert(num);
        }
        for (const auto& num : nums) {
            // 只有连续子序列的头部才可能更新最大长度
            // 也因此，数组中每个元素只会在下面的内层循环中遍历一次，复杂度O(n)
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }
            int cnt = 1;
            int cur = num + 1;
            while (num_set.find(cur) != num_set.end()) {
                cnt++;
                cur++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};

// 执行用时：20 ms, 在所有 C++ 提交中击败了79.56% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了9.69% 的用户
// 时间复杂度为O(nlogn)，写复杂了，还不如直接排序，时间复杂度是一样的
int BFlongestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = 1;
    set<int> no;
    for (auto& i : nums) {
        no.insert(i);  // set的插入复杂度为O(logn)
    }
    auto i = no.begin();
    int t = 1;
    int f = *i;
    i++;
    for (; i != no.end(); i++) {
        if (*i - (long)f == 1) {
            t++;
            if (t > res) res = t;
        } else {
            t = 1;
        }
        f = *i;
    }
    return res;
}
// 执行用时：16 ms, 在所有 C++ 提交中击败了95.98% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了13.98% 的用户
// 关键在于连续，前面尝试过的值后面不用再找，但复杂度应该也不是O(n)
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = 1;
    unordered_set<long> no(
        nums.begin(),
        nums.end());  // 注意这里必须是long，否则下面的用例结果会是2
                      // 否则count(2147483648)返回不是0

    for (auto& i : nums) {
        long pre = (long)i - 1, next = (long)i + 1;
        while (no.count(pre)) no.erase(pre--);
        while (no.count(next)) no.erase(next++);
        if (next - pre - 1 > res) res = next - pre - 1;
    }

    return res;
}

int main() {
    vector<int> nums({2147483647, -2147483648});
    cout << longestConsecutive(nums) << endl;
}