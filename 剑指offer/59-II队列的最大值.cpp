#include <bits/stdc++.h>
using namespace std;

// 执行用时：124 ms, 在所有 C++ 提交中击败了96.49% 的用户
// 内存消耗：47.9 MB, 在所有 C++ 提交中击败了42.00% 的用户
class MaxQueue {
private:
    struct val_idxp{
        int val;
        int idx;
    };
    int nextidx = 0;
    queue<val_idxp> q;
    deque<val_idxp> m;//根据上一题的原理维护可能是队列最大值的数        注意要用双端队列
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(m.empty())return -1;
        else return m.front().val;
    }
    
    void push_back(int value) {
        val_idxp t = {value, nextidx};
        nextidx++;
        q.push(t);
        if(m.empty())m.push_back(t);
        else{
            while(!m.empty() && t.val > m.back().val){
                m.pop_back();//此处尾部出列
            }
            m.push_back(t);
        }
    }
    
    int pop_front() {
        if(q.empty())return -1;
        val_idxp tq = q.front(), tm = m.front();
        q.pop();
        if(tq.idx == tm.idx)m.pop_front();//此处头部出列
        return tq.val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(){
    cout << "print sth." << endl;
}