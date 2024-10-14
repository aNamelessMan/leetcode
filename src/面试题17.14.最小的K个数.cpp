#include <bits/stdc++.h>

using namespace std;

// 即top k
// 空间复杂度：O(k)，因为大根堆里最多 k 个数。
class HeapSortSolution {
public:
    // 大顶堆
    class PQ {
    public:
        // 因为container_[0]是闲置的，所以需要的空间得 +1
        // 对于下标为k的节点，其左右子节点分别为 2 * k, 2 * k + 1
        // 其父节点为 k / 2
        PQ(int capacity)
            : capacity_(capacity + 1), ptr_(1), container_(capacity + 1, 0) {}
        // 将下标为k的元素上浮到合适位置
        // 用于在push新元素时先放末尾再上浮到合适位置
        void swim(int k) {
            // 不是根节点且比父节点大，就一直上浮
            while (k > 1 && container_[k / 2] < container_[k]) {
                swap(container_[k / 2], container_[k]);
                k = k / 2;
            }
        }
        // 将指定元素下沉到合适位置
        // 用于在删除堆顶元素时，将末尾元素放到顶部，再下沉到合适位置
        void sink(int k) {
            while (2 * k < ptr_) {  // 即有子节点
                int j = 2 * k;
                // 取左右子节点里更大的那个
                if (j < ptr_ - 1 && container_[j] < container_[j + 1]) j++;
                // 如果子节点大于父节点，则将父节点下沉，否则结束
                if (!(container_[k] < container_[j])) break;
                swap(container_[k], container_[j]);
                // 开始下一轮下沉
                k = j;
            }
        }
        void push(int num) {
            container_[ptr_] = num;
            swim(ptr_);
            ptr_++;
        }
        void pop() {
            swap(container_[1], container_[ptr_ - 1]);
            ptr_--;
            sink(1);
        }
        int top() { return container_[1]; }

    private:
        int capacity_ = 0;
        int ptr_ = 1;  // 下一个push进来元素的位置，即右开区间
        vector<int> container_;
    };
    vector<int> smallestK(vector<int>& arr, int k) {
        int sz = arr.size();
        if (sz <= k) return arr;
        if (k == 0) return vector<int>();
        PQ pq(k);
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        for (int i = k; i < sz; i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// 快排: 时间复杂度：期望为 O(n)
// ，由于证明过程很繁琐，所以不在这里展开讲。具体证明可以参考《算法导论》第 9
// 章第 2 小节。
class QuickSortSolution {
public:
    int partition(vector<int>& arr, int l, int r) {
        int pos = l;
        for (int i = l; i < r - 1; i++) {
            if (arr[i] < arr[r - 1]) {
                swap(arr[i], arr[pos]);
                pos++;
            }
        }
        swap(arr[r - 1], arr[pos]);
        return pos;
    }
    void quick_sort(vector<int>& arr, int k, int l, int r) {
        if (l >= r) return;
        if (l >= k) return;
        int pos = partition(arr, l, r);
        quick_sort(arr, k, l, pos);
        quick_sort(arr, k, pos + 1, r);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0) return vector<int>();
        quick_sort(arr, k, 0, arr.size());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
