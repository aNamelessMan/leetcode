#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int num, int target) { return num <= target; }
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l = 0;
        int r = sz - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(nums[mid], target)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
// 20241010 阿里控股/智能引擎 一面 非降序数组，求target最后一次出现位置
int main() {
    vector<int> nums{100, 3000, 4000, 20000, 20000, 20000, 30000};
    int target = 20000;
    // 最后一个出现的位置下标应该是5
    Solution a;
    cout << a.search(nums, target) << endl;
}
