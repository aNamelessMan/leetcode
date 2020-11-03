#include<bits/stdc++.h>
using namespace std;
// 执行用时：432 ms, 在所有 C++ 提交中击败了32.66% 的用户
// 内存消耗：104.6 MB, 在所有 C++ 提交中击败了8.16% 的用户
//单调队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //递减(双端)队列，确保队首是队列中最大的值，且队列中只有窗口中的值
    //队列中存的是下标
    if(nums.empty())return {};
    vector<int> res;
    int n = nums.size();
    deque<int> idx;
    
    for(int i = 0; i < n; i++){
        if(!idx.empty() && idx.front() == i - k)idx.pop_front();//如果队列首不在窗口中，出队
        while(!idx.empty() && nums[idx.back()] < nums[i])idx.pop_back();//确保递减  注意是是跟队尾比较
        idx.push_back(i);
        if(i > k - 2)res.push_back(nums[idx.front()]);
    }

    return res;
}


//暴力解法TLE 49 / 59 个通过测试用例
vector<int> BFmaxSlidingWindow(vector<int>& nums, int k) {
    if(nums.empty())return {};
    vector<int> res;
    int n = nums.size();
    for(int i = 0; i < n - k + 1; i++){
        int t = INT_MIN;
        for(int j = i; j < i + k; j++){
            if(nums[j] > t)t = nums[j];
        }
        res.push_back(t);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}