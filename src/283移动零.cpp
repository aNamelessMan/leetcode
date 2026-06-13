#include <bits/stdc++.h>
using namespace std;

// 执行用时分布0ms击败100.00%
// 消耗内存分布25.08MB击败5.16%
class Solution260614 {
public:
  // 注意比较函数实现的是严格弱序关系，n1是否必须放在n2前，是则true，否（包含相等的情况）则false
  static bool compare(const int &n1, const int &n2) {
    if (n2 == 0) {
      return 1;
    }
    return 0;
  }
  void moveZeroes(vector<int> &nums) {
    stable_sort(nums.begin(), nums.end(), compare);
  }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了91.09% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了9.35% 的用户
void moveZeroes20210420(vector<int> &nums) {
  int toput = 0, zeroCnt = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      zeroCnt++;
    } else {
      nums[toput] = nums[i];
      toput++;
    }
  }
  for (int i = toput; i < n; i++) {
    nums[i] = 0;
  }
  return;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.02% 的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了5.23% 的用户
// 双指针
void moveZeroes(vector<int> &nums) {
  int i = 0, p = 0,
      n = nums.size(); // i是当前遍历的下标，p是下一个非零数存放的位置
  while (i < n) {
    if (nums[i]) {
      nums[p] = nums[i];
      p++;
    }
    i++;
  }
  while (p < n) {
    nums[p] = 0;
    p++;
  }
}

int main() { cout << 1 << endl; }