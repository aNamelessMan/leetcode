#include <bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了96.82% 的用户
// 内存消耗：38.4 MB, 在所有 C++ 提交中击败了85.33% 的用户
int sumSubarrayMins(vector<int>& arr) {
    /*最小值为A[i]的子数组包括  
        以A[i]为左边界且A[i]最小的子数组    个数为  左边比A[i]大的连续子数组长度l
        以A[i]为右边界且A[i]最小的子数组    个数为  右边比A[i]大的连续子数组长度r
        A[i]在中间且A[i]最小的子数组        个数为l * r
        再加上只有A[i]的子数组个数为1
        l + r + l * r + 1
    因此知道了左右第一个比A[i]小的元素位置就可以直接算出A[i]会被计算几次
    要知道左右第一个比A[i]小的元素位置需要单调栈
    参考LC84题，思路一模一样
    */
    long res = 0;
    stack<int>stk;
    for(int i = 0, n = arr.size(); i < n; i++){
        if(stk.empty() || arr[stk.top()] <= arr[i]){//维护递增栈
            stk.push(i);
        }else{
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                //将栈顶出栈，栈顶的前一个元素是在该元素左边且低于它的最近的元素，将要入栈的元素i是在该元素右边且低于它的最近的元素
                int t = stk.top();
                stk.pop();
                long l, r = i - t - 1;
                if(stk.empty()){
                    l = t;
                }else{
                    l = t - stk.top() - 1;
                }
                res += (1 + l + r + l * r) * arr[t];
            }
            stk.push(i);
        }
    }
    int n = arr.size();//栈中剩余的元素，说明右侧没有比他更小的元素了，r = n - 1 - i
    while(!stk.empty()){
        int i = stk.top();
        stk.pop();
        long r = n - 1 - i, l;
        if(stk.empty()){
            l = i;
        }else{
            l = i - stk.top() - 1;
        }
        res += (1 + l + r + l * r) * arr[i];
    }
    return res % int(1e9 + 7);
}

int main(){
    vector<int> arr{3, 1, 2, 4};
    cout << sumSubarrayMins(arr) << endl;
}