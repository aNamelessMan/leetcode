#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> res;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      int num = abs(nums[i]);

      if (nums[num - 1] > 0) {
        nums[num - 1] *= -1;
      } else {
        res.push_back(num);
      }
    }
    return res;
  }
};