#include <iostream>
#include <vector>

using namespace std;

static int global_target = 5;

int binarysearch(std::vector<int> &A, int target, int l, int h) {
    if (h < l) return -1;
    int mid = (h + l) / 2;
    if (A[mid] == target) return mid;
    if (A[mid] < target)
        return binarysearch(A, target, mid + 1, h);
    else
        return binarysearch(A, target, l, mid - 1);
}

int binarysearch(std::vector<int> &A, int target) {
    return binarysearch(A, target, 0, A.size() - 1);
}

/**
 * 二分的本质与单调性无关
 * 它的本质是 对于一段区间，有某个性质，左区间中元素都不满足，右区间元素都满足
 * 那么二分可以找到左右区间的边界
 *
 * 所以如果区间满足上述性质，那么我们就可以套用下面的二分模板来找边界
 * 首先定义好性质检查函数，check，即给定区间中一个元素，满足性质则返回true，不满足则返回false
 * 然后按常规想法二分即可
 * 注意有 l = mid时需要 mid = (l + r + 1) / 2，即向上取整
 * 因为如果不向上取整，当l + 1 = r时，mid永远是l
 */

// yxc的二分模板
// 找出第一个大于等于target的数
// 即找出第一个满足某性质的数，右区间的左边界
bool check1(int i) { return i >= global_target; }
int bs1(const std::vector<int> &vi, int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (check1(vi[mid])) {
            // 满足性质，那么该边界点一定在mid左边，且可能是mid本身
            r = mid;
        } else {
            // 不满足性质，那么该边界点一定在mid右边
            l = mid + 1;
        }
    }
    return l;
}
// 找出最后一个小于等于target的数
// 即找出最后一个不满足某性质的数，左区间的右边界
// 小于等于target => 不大于target
// 那么这个性质应该是 大于target
bool check2(int i) { return i > global_target; }
int bs2(const std::vector<int> &vi, int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        // l = mid需要向上取整，防止死循环
        if (check2(vi[mid])) {
            // 满足性质，那么边界一定是在mid之前
            r = mid - 1;
        } else {
            // 不满足性质，那么边界一定在mid之后，也可能是mid
            l = mid;
        }
    }
    return l;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    cout << "bs1: " << nums[bs1(nums, 0, nums.size() - 1)] << endl;
    cout << "bs2: " << nums[bs2(nums, 0, nums.size() - 1)] << endl;
}
