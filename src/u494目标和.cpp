#include<bits/stdc++.h>
using namespace std;
//139 / 139 个通过测试用例  TLE
int res = 0;
void dfs(vector<int>& nums, int S, unsigned n, int curSum){
    if(curSum == S && n == nums.size())res++;
    else if(n == nums.size())return;
    else{
        curSum += nums[n];n++;
        dfs(nums, S, n, curSum);
        //注意n和curSum都要还原，而且必须按照这个顺序
        n--;curSum -= nums[n];
        curSum -= nums[n];n++;
        dfs(nums, S, n, curSum);
    }
}
int findTargetSumWays(vector<int>& nums, int S) {
    dfs(nums, S, 0, 0);
    return res;
}

int main(){
    vector<int> nums{1,1,1,1,1};
    int S = 3;
    cout << findTargetSumWays(nums, S) << endl;
}