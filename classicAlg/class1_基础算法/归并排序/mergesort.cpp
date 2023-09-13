#include <queue>
#include <vector>

using namespace std;

void merge(std::vector<int>& A, int l, int mid, int h) {
    int p1 = l, p2 = mid + 1;  // 左半段
    std::queue<int> q;
    while (p1 != mid + 1 || p2 != h + 1) {
        if (p1 == mid + 1) {
            q.push(A[p2]);
            p2++;
        } else if (p2 == h + 1) {
            q.push(A[p1]);
            p1++;
        } else {
            if (A[p1] < A[p2]) {
                q.push(A[p1]);
                p1++;
            } else {
                q.push(A[p2]);
                p2++;
            }
        }
    }
    for (int i = l; i <= h; i++) {
        A[i] = q.front();
        q.pop();
    }
}
/**
 * 分治
 * 1. 确定分界点 mid = (l + r) / 2
 * 2. 递归排序左右两边
 * 3. 归并
 */

void mergesort(std::vector<int>& A, int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void mergesort(std::vector<int>& A) { mergesort(A, 0, A.size() - 1); }

/**
 * 可用于求逆序对的数量
 * 逆序对：任意选两个数（组合Cm n），前一个数大于后一个数，则称为一个逆序对
 *
 * 1. 先假设merge_sort可以返回区间中逆序对的数量
 * 2. 那么 C(A) = C(A_l) + C(A_r) + A_l中数和A_r中数构成的逆序对个数
 * 3. 那么问题就变成计算 左区间数 和 右区间数 能构成的逆序对个数
 * 如果归并时遇到相等数时，优先将左区间入队，那么当右区间入队时，一定是左区间队首大于右区间队首
 * 那么这个右区间的队首贡献了 size(A_l) 个逆序对
 * 因为有序，所以左区间的剩下所有数都可以和这个队首构成逆序对
 */
class Solution {
public:
    int Merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
        int res = 0;
        int i1 = l1;
        int i2 = l2;
        queue<int> q;
        while (i1 <= r1 || i2 <= r2) {
            if (i1 > r1) {
                q.push(nums[i2]);
                i2++;
            } else if (i2 > r2) {
                q.push(nums[i1]);
                i1++;
            } else {
                if (nums[i1] > nums[i2]) {
                    q.push(nums[i2]);
                    i2++;
                    res += r1 - i1 + 1;
                } else {
                    q.push(nums[i1]);
                    i1++;
                }
            }
        }
        for (int i = l1; i <= r2; i++) {
            nums[i] = q.front();
            q.pop();
        }
        return res;
    }
    int MergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        int res_l = MergeSort(nums, l, mid);
        int res_r = MergeSort(nums, mid + 1, r);
        return res_l + res_r + Merge(nums, l, mid, mid + 1, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return MergeSort(nums, 0, n - 1);
    }
};
