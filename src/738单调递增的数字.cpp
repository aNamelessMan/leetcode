#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了5.07% 的用户
int monotoneIncreasingDigits(int N) {
    stack<int> num;
    stack<int> res;
    while(N){
        num.push(N % 10);
        N /= 10;
    }
    int n = num.size();

    while((int)res.size() != n){
        if(res.empty() || num.top() >= res.top()){
            res.push(num.top());
            num.pop();
        }else{
            //当遇到非递增情况时，必须找到一个数减一后仍然大于大于前一个数
            int t = res.top();
            res.pop();
            while(!res.empty() && t - 1 < res.top()){
                t = res.top();
                res.pop();
            }
            res.push(t - 1);
            while((int)res.size() != n){
                res.push(9);
            }
        }
    }
    stack<int> ans;

    while(!res.empty()){
        ans.push(res.top());
        res.pop();
    }

    int r = 0;
    for(int i = 0; i < n; i++){
        r = 10 * r + ans.top();
        ans.pop();
    }
    return r;
}

int main(){
    cout << monotoneIncreasingDigits(10) << endl;
    cout << monotoneIncreasingDigits(20) << endl;
    cout << monotoneIncreasingDigits(120) << endl;
    cout << monotoneIncreasingDigits(332) << endl;
    cout << monotoneIncreasingDigits(999998) << endl;
}