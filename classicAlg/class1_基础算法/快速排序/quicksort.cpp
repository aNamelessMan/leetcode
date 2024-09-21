#include <algorithm>
#include <vector>

// TODO: 每次都取最右侧，对于所有元素都相同的输入会退化到O（n^2）
int partition(std::vector<int> &A, int l, int h) {
    /*
    用数组中的最后一个元素A[h]来分割数组
        也就是既要放在排序后正确的位置toset
        同时也要保证该位置前的所有元素都小于A[h]，该位置后的所有元素都大于等于A[h]
    */
    int toset = l;  // 以下循环结束后  会保证所有比A[h]小的元素都在toset之前 且
                    // A[toset] >= A[h]
    for (int i = l; i < h; i++) {
        if (A[i] <
            A[h]) {  // 遍历到比A[h]小的元素，最终需要放到A[h]之前，因此将该元素放置到toset的位置，并将toset加1
            std::swap(A[i], A[toset]);
            toset++;
        }
    }
    std::swap(A[toset], A[h]);  // 将A[h]放到计算好的位置
    return toset;
}

/**
 * 分治
 * 1. 选择分界点x
 * 2. 调整区间，左区间都<=x, 右区间都>=x
 * 3. 递归处理左右两边
 */

void quicksort(std::vector<int> &A, int l, int h) {
    if (l < h) {
        // 将A[h]放到正确的位置p，且p之前的元素都小于A[p]，p之后的元素都大于等于A[p]，因此只需再把前后子数组排序完成即可
        int p = partition(A, l, h);
        /*!!!
        此外因为这一步将A[p]元素放到了合适的位置p，所以如果需要找数组中第k大的数，可以根据p与k的大小关系缩小查找范围
            p < k   return quicksort(A, p + 1, h);  必在子数组A[p + 1, h]中
            p == k  return A[p];
            p > k   return quicksort(A, l, p - 1);  必在子数组A[l, p - 1]中
        */
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, h);
    }
}

void quicksort(std::vector<int> &A) {
    std::random_shuffle(A.begin(),
                        A.end());  // 但这样对于全部一样的数仍然会退化到n^2
    quicksort(A, 0, A.size() - 1);
}

// 也可以用于找第k大的数，复杂度O（n）见leetcode#215
int quickselect(std::vector<int> &A, int k, int l, int r) {
    int p = partition(A, l, r);
    if (k == p - l + 1)
        return A[p];
    else if (k <= p - l)
        return quickselect(A, k, l, p - 1);
    else
        return quickselect(A, k - (p - l + 1), p + 1, r);
}
int quickselect(std::vector<int> &A, int k) {
    int l = 0;
    int r = A.size() - 1;
    return quickselect(A, k, l, r);
}

/*

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& input, int l, int r) {
    int t = input[r - 1];
    int to_set = l;
    for (int i = l; i < r - 1; i++) {
        if (input[i] < t) {
            std::swap(input[i], input[to_set]);
            to_set ++;
        }
    }
    std::swap(input[r- 1], input[to_set]);
    return to_set;
}

void quick_sort(vector<int>& input, int l, int r) {
    if (l>= r) return;
    int p = partition(input, l, r);
    quick_sort(input, l, p);
    quick_sort(input, p + 1, r);
}

int main() {
    int sz;
    cin >> sz;
    vector<int> arr;
    arr.reserve(sz);
    int t;
    while (cin >> t) {
        arr.push_back(t);
    }

    // 打乱 加 特判 过 有序 和 全都一样 的 用例
    std::random_shuffle(arr.begin(), arr.end());
    int first = arr[0];
    int i = 1;
    for (; i < sz; i++) {
        if (arr[i] != first) break;
    }
    if (i != sz) {
        quick_sort(arr, 0, sz);
    }

    for (const auto& no : arr) {
        cout << no << " ";
    }
    cout << endl;
}
*/
