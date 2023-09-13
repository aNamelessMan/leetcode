#include <iostream>
#include <vector>

using namespace std;

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
 * 所以如果区间满足上述性质，那么我们就可以套用下面的整数二分模板来找边界
 * 1. 首先定义好性质：
 *    并且对于该段区间，存在一个划分，使得左区间中元素都不满足，右区间元素都满足该性质
 *    然后实现性质检查函数check，即给定区间中一个元素
 *      a. 满足性质则返回true
 *      b. 不满足则返回false
 * 2. 思考如何根据check返回来更新查找范围
 * 3. 不断迭代二分，直到不满足l < r
 * 4. 注意有 l = mid时需要 mid = (l + r + 1) / 2，即向上取整
 *    因为如果不向上取整，当l + 1 = r时，mid永远是l
 * 5. 二分一定会返回一个边界，
 *    但如果题目本身不保证一定有解，此时这个边界会是错的，
 *    这种情况需要最后判断，边界元素是否满足要求，即该题的该case是否有解
 */

static int global_target = 5;

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
