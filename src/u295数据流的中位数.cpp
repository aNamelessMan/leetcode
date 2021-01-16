#include<bits/stdc++.h>
using namespace std;

// 执行用时：136 ms, 在所有 C++ 提交中击败了99.29% 的用户
// 内存消耗：41.2 MB, 在所有 C++ 提交中击败了48.37% 的用户
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : 0.5 *(small.top() - large.top());
    }
private:
    priority_queue<long> small, large;//small是小顶堆，我们将数字取反后再添加进large就是大顶堆
    //维护前半部分在小顶堆，后半部分在大顶堆，小顶堆可能比大顶堆个数多一
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    cout << "print something." << endl;
}