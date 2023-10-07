#include <bits/stdc++.h>

using namespace std;
/*
对每个元素，求 左边/右边 离它最近的 小于/大于 它的数

以求左边最近的小于它的数为例
当向右迭代时，如果栈顶元素大于等于当前遍历到的元素，那么栈顶元素在之后不可能被用到
因为有比它更近且更小的数了
pop直到满足小于当前元素的值，即为当前解，并将当前元素push
*/
int main() {
    int n, t;
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        cin >> t;
        while (!stk.empty() && stk.top() >= t) {
            stk.pop();
        }
        if (stk.empty()) {
            cout << "-1 ";
        } else {
            cout << stk.top() << " ";
        }
        stk.push(t);
    }
    cout << endl;
}
