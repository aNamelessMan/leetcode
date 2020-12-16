#include<bits/stdc++.h>
using namespace std;

// 给你一个长度为N的整型数组arr，使用下标从0到N-1，
// 请你选出两个数p q 要求 0<p<q<N−1 q−p>1，求出arr[p]+arr[q]的最小值
int splitArray(vector<int> &arr) {
    int res = INT_MAX, n = arr.size();
    int dp[n];//dp[i]代表nums[i] 到 nums[n - 1]的最小值    范围由1到n - 2
    dp[n - 2] = arr[n - 2];//初始条件
    for(int i = n - 3; i > 0; i--){//递推关系
        if(arr[i] < dp[i + 1])dp[i] = arr[i];
        else    dp[i] = dp[i + 1];
    }
    //直接暴力解法会超时
    for(int i = 1; i + 2 < n - 1; i++){
        if(res > arr[i] + dp[i + 2])res = arr[i] + dp[i + 2];
    }
    return res;
}

int main(){
    cout << 1 << endl;
}