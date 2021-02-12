#include <bits/stdc++.h>
using namespace std;

static bool comp(const vector<int> &v1, const vector<int> &v2){
    return v1[1] < v2[1];//按会议结束时间从早到晚排序
}
/*  01背包dp+bs
 * 令dp[i][k]为可以参加前i个会议中k个时所能取得的最大收益
 * 则递推公式如下：
 * dp[i][k] = 
 *  1.不参加第i个会议   dp[i - 1][0 - k]个的最大值
 *  2.参加第i个会议，则需要排除所有结束时间晚于第i个会议开始时间的会议，因此要找到最后一个结束时间早于第i个会议的会议j  dp[j][k - 1] + events[i]  
 * 取以上两个中的最大值作为dp[i][k]
 *  
 * 为了快速找到最后一个结束时间晚于第i个会议的会议j，需要先将会议按结束时间从早到晚排序，然后使用二分查找
 * 执行用时：372 ms, 在所有 C++ 提交中击败了54.78% 的用户
 * 内存消耗：61.8 MB, 在所有 C++ 提交中击败了77.94% 的用户
 */
int maxValue(vector<vector<int>>& events, int k) {
    int n = events.size();
    if(n == 0)return 0;
    sort(events.begin(), events.end(), comp);
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    dp[0][1] = events[0][2];
    for(int i = 1; i < n; i++){//注意每一步要更新dp[i]这一行的k个值
        //不参加第i个
        for(int j = 0; j <= k; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        //参加第i个
        int st = events[i][1];
        int l = 0, r = i;//找到最后一个结束时间早于i开始时间的会议  左闭右开注意r所指的会议已经被排除[l, r)
        while (r - l > 1) {//只要剩余部分不止一个就继续排除
            int mid = (l + r) / 2;
            if (events[mid][1] >= events[i][0]) {//mid结束时间大于等于开始时间  排除mid及其之后的部分
                r = mid;
            } else {//小于  排除mid之前的部分
                l = mid;
            }
        }//注意此时可能没有符合条件的会议
        if (events[l][1] < events[i][0]) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i][j], dp[l][j-1] + events[i][2]);
            }
        } else {//没有会议结束时间早于第i个会议开始时间，因此只能修改dp[i][1]
            dp[i][1] = max(dp[i][1], events[i][2]);
        }
    }
    int ret = 0;
    for (int i = 0; i <= k; i++) {
        ret = max(ret, dp[n-1][i]);
    }
    return ret;
}

//dfs   63 / 65 个通过测试用例  TLE
void dfs(int start, int n, vector<vector<int>>& events, vector<vector<int>>& pres, int cur, int k, int &res){
    if(k == 0 || start == n)return;
    for(int i = start; i < n; i++){
        if(!pres.empty() && events[i][0] <= pres.back()[1])continue;
        
        cur += events[i][2];
        pres.push_back(events[i]);
        res = max(res, cur);
        dfs(i, n, events, pres, cur, k - 1, res);
        cur -= events[i][2];
        pres.pop_back();
    }
}
    
int BFmaxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), comp);
    vector<vector<int>> pres;
    int res = 0, n = events.size();
    dfs(0, n, events, pres, 0, k, res);
    return res;
}

int main(){
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    maxValue(events, 2);
}