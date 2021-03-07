#include <bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了97.22% 的用户
// 内存消耗：15.6 MB, 在所有 C++ 提交中击败了48.53% 的用户
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //维护一个 单调递减 且 范围大小小于等于k 的队列，这样队首就是该窗口的最大值，队列只有可能是最大值的数的下标
    //如果队列尾的数比要入队的数小，拿他一定不可能成为窗口最大值，  因为他既小于即将入队的值，又比即将入队的值先出窗口
    vector<int> res;
    deque<int> dq;
    int n = nums.size();
    for(int i = 0; i < n; i++){//即将把i入队，也就是把nums[i]加入窗口
        if(dq.empty()){
            dq.push_back(i);
        }
        else{
            while(!dq.empty() && i - dq.front() + 1 > k){//维护窗口大小
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){//维护单调减
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(i >= k - 1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}