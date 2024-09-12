#include <functional>
#include <iostream>
#include <queue>

using namespace std;
// 暂时先这么写吧。。。
int main() {
    vector<int> input{2, 23, 43, 34, 23, 65, 57, 6, 868, 565, 32};
    // 默认大顶堆
    priority_queue<int> heap(input.begin(), input.end());
    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> heap1(input.begin(),
                                                         input.end());
    while (!heap1.empty()) {
        cout << heap1.top() << " ";
        heap1.pop();
    }
    cout << endl;
}
