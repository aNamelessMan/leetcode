#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了70.79% 的用户
vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> res;
    int start, starti, i = 0;
    while(i < n){
        start = nums[i];
        starti = i;
        i++;
        while(i < n && ((i == 0) || (long)nums[i] - nums[i - 1] == 1)){
            i++;
        }
        if(i == starti + 1){
            res.push_back(to_string(nums[starti]));
        }else{
            string tmp = to_string(nums[starti]);
            tmp += "->";
            tmp += to_string(nums[i - 1]);
            res.push_back(tmp);
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}