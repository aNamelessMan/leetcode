#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &arr) {
    int res = INT_MAX, n = arr.size();
    int dp[n];//dp代表从此处往后的最小值    范围由1到n - 2
    dp[n - 2] = arr[n - 2];
    for(int i = n - 3; i > 0; i--){
        if(arr[i] < dp[i + 1])dp[i] = arr[i];
        else    dp[i] = dp[i + 1];
    }
    for(int i = 1; i + 2 < n - 1; i++){
        if(res > arr[i] + dp[i + 2])res = arr[i] + dp[i + 2];
    }
    return res;
}

int main(){
    cout << 1 << endl;
}