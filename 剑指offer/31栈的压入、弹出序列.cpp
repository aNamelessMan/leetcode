#include <bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.21% 的用户
// 内存消耗：14.6 MB, 在所有 C++ 提交中击败了92.89% 的用户
//模拟压入弹出顺序即可
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    int i = 0, j = 0;
    stack<int> stk;
    while(i < n){//边压入边尝试弹出，如果不能弹则继续压入
        if(stk.empty() || stk.top() != popped[j]){
            stk.push(pushed[i]);
            i++;
        }else{
            stk.pop();
            j++;
        }
    }
    while(j < n && popped[j] == stk.top()){//在所有元素压入后，尝试能否按顺序弹出
        j++;
        stk.pop();
    }
    return j == n;
}

int main(){
    cout << "print sth." << endl;
}