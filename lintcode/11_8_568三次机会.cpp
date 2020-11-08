#include<bits/stdc++.h>
using namespace std;

int threeChances(vector<int> &nums) {
    int res = INT_MIN;
    int n = nums.size();
    if(n <= 4)return n;
    
    //int dp[n];
    vector<int> dp(n, 0);
    dp[0] = 0;
    int dpt = 0;
    while(nums[dpt] == nums[0]){
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
        
        if(j < n && nums[j] == t)no += dp[j];
        
        res = max(res, no);
    }
    return res;
}

int main(){
    vector<int> nums({0,3,1,0,6,3});
    cout << threeChances(nums) << endl;
}