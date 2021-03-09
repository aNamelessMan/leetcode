#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了52.09% 的用户
// 内存消耗：14 MB, 在所有 C++ 提交中击败了68.74% 的用户
//2021.3.9二刷还是不会写...
/*注意到每个下标可以增加的水量等于  max(0, min(左边最高边, 右边最高边) - 他的长度)
因此只需要计算出    每个边左边和右边的最长边即可
*/
int trap(vector<int>& height) {
    int n = height.size(), res = 0;
    if(n <= 2)return res;
    vector<int> dp(n, 0);

    dp[0] = height[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1], height[i]);
    }

    dp[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 1; i--){
        res += max(min(dp[i - 1], dp[i + 1]) - height[i], 0);
        dp[i] = max(dp[i + 1], height[i]);
    }
    return res;
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了14.13% 的用户
// 内存消耗：14.1 MB, 在所有 C++ 提交中击败了5.02% 的用户
//两边扫描+dp
//第一遍在dp[i]中存入i位置左边的最大值
//第二遍找右边最大值，取两个最值中更小的那个与height[i]作差并加到结果中
int dptrap(vector<int>& height) {
    if(height.size() < 3)return 0;
    int res = 0, mx = 0;
    vector<int> dp(height.size(), 0);
    for(int i = 0; i < (int)height.size(); i++){
        dp[i] = mx;
        mx = max(mx, height[i]);
    }
    mx = 0;
    for(int i = height.size() - 1; i > -1; i--){
        int tmp = min(mx, dp[i]);
        if(tmp > height[i])res += (tmp - height[i]);
        dp[i] = mx;
        mx = max(mx, height[i]);
    }
    return res;
}

//314 / 315 个通过测试用例 TLE
int BFtrap(vector<int>& height) {
    if(height.empty())return 0;
    int res = 0;
    int m = *max_element(height.begin(), height.end());
    for(int i = 1; i < m + 1; i++){
        for(auto &h:height){
            if(h < i)
                res++;
        }
        for(int j = 0; j < (int)height.size(); j++){
            if(height[j] < i)res--;
            else break;
        }
        for(int j = height.size() - 1; j >= 0; j--){
            if(height[j] < i)res--;
            else break;
        }
    }
    return res;
}

int main(){
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << dptrap(nums) << endl;
}