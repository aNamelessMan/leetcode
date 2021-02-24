#include <bits/stdc++.h>
using namespace std;

// 执行用时：312 ms, 在所有 C++ 提交中击败了95.00% 的用户
// 内存消耗：101 MB, 在所有 C++ 提交中击败了85.03% 的用户
//复杂度O(1)
class CQueue {
private:
    stack<int> stk1;//stk1维护队列的顺序
    stack<int> stk2;//stk2用来输出
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if(stk2.empty())return -1;
        int res = stk2.top();
        stk2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(){
    cout << "print sth." << endl;
}