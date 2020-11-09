#include<bits/stdc++.h>
using namespace std;
/*
给出一个整数数组，所有的元素都在 [−10,10][-10, 10][−10,10] 之间。
你有三次机会将数组中的一个数替换成任意数。
请求出可能的最长相等子段数列的长度。
*/
int threeChances(vector<int> &nums) {
    int res = INT_MIN;
    int n = nums.size();
    if(n <= 4)return n;
    //dp[i]表示从当前值开始有几个与nums[i]相等的值(至少为1)
    //暴力解法会超时
    int dp[n];
    //vector<int> dp(n, 0);
    dp[0] = 0;
    int dpt = 0;
    while(dpt < n && nums[dpt] == nums[0]){//每次[x]下标操作符中是变量时，都要判断(思考)是不是会越界
        dp[0]++;
        dpt++;
    }
    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i - 1]){
            dp[i] = dp[i - 1] - 1;
        }else{
            dp[i] = 0;
            int j = i;
            while(j < n && nums[j] == nums[i]){
                j++;
                dp[i]++;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int j = i;
        int t = nums[i], chance = 3, no = 0;
        
        no += dp[i];
        j += dp[i];
        
        while(chance > 0 && j < n){
            if(nums[j] != t)chance--;
            j++;
            no++;
        }
        
        if(j < n && nums[j] == t)no += dp[j];//每次[x]下标操作符中是变量时，都要判断(思考)是不是会越界
        
        res = max(res, no);
    }
    return res;
}

int main(){
    vector<int> nums({0,3,1,0,6,3});
    cout << threeChances(nums) << endl;
}