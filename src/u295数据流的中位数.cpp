#include <bits/stdc++.h>
using namespace std;

class MedianFinder230926 {
public:
    MedianFinder230926() {}

    void addNum(int num) {
        big_heap_.push(num);
        if (big_heap_.size() > small_heap_.size()) {
            double t = big_heap_.top();
            big_heap_.pop();
            small_heap_.push(t);
        }
        // 防止大顶堆中存在大于小顶堆的数
        // 每次add最多只可能需要处理一个数
        if (!big_heap_.empty() && !small_heap_.empty() &&
            big_heap_.top() > small_heap_.top()) {
            int b = big_heap_.top();
            int s = small_heap_.top();
            big_heap_.pop();
            small_heap_.pop();
            big_heap_.push(s);
            small_heap_.push(b);
        }
    }

    double findMedian() {
        if (big_heap_.size() == small_heap_.size()) {
            return (big_heap_.top() + small_heap_.top()) / 2;
        } else {
            return small_heap_.top();
        }
    }

private:
    priority_queue<double> big_heap_;
    priority_queue<double, vector<double>, greater<double>> small_heap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 执行用时：140 ms, 在所有 C++ 提交中击败了63.50% 的用户
// 内存消耗：46.3 MB, 在所有 C++ 提交中击败了11.09% 的用户
class MedianFinder {
private:
    priority_queue<double> bq;  // 存放偏小的那一半数据
    priority_queue<double> sq;  // 存放偏大的那一半数据
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        bq.push(num);
        if (bq.size() > sq.size() + 1) {  // 确保两个堆中元素个数相差不超过1
            int t = bq.top();
            bq.pop();
            sq.push(-t);
        }
        if (!bq.empty() && !sq.empty() &&
            bq.top() > -sq.top()) {  // 防止较大的数停留在小一半的堆中
                                     // 必须确保sq中的最大值 都小于 bq中的最小值
            int b = bq.top(), s = sq.top();
            bq.pop();
            sq.pop();
            bq.push(-s);
            sq.push(-b);
        }
    }

    double findMedian() {
        if (bq.size() == sq.size())
            return double(bq.top() - sq.top()) / 2;
        else
            return bq.top();
    }
};

// 执行用时：136 ms, 在所有 C++ 提交中击败了99.29% 的用户
// 内存消耗：41.2 MB, 在所有 C++ 提交中击败了48.37% 的用户
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size() ? small.top()
                                           : 0.5 * (small.top() - large.top());
    }

private:
    priority_queue<long> small,
        large;  // small是小顶堆，我们将数字取反后再添加进large就是大顶堆
    // 维护前半部分在小顶堆，后半部分在大顶堆，小顶堆可能比大顶堆个数多一
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() { cout << "print something." << endl; }