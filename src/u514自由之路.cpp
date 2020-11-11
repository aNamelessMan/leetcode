#include<bits/stdc++.h>
using namespace std;

//514 493 373这三道题好像有些联系
//找时间看下文章    https://leetcode.com/problems/reverse-pairs/discuss/97268/general-principles-behind-problems-similar-to-reverse-pairs

// 执行用时：380 ms, 在所有 C++ 提交中击败了8.84% 的用户
// 内存消耗：13.3 MB, 在所有 C++ 提交中击败了27.07% 的用户
//dp[i][j]代表当12点位置是ring[j]时转到key[i]的最小步数 不包含确定所用的步数，因为可以在最后再统一加上
//因此最后结果为dp[0][0] + key.size()
int findRotateSteps(string ring, string key) {
    int m = ring.size(), n = key.size();
    vector<vector<int>> dp(n + 1, vector<int>(m));//此时dp[n][*]默认0，好处是可以把初始化dp[n - 1][*]的过程合并到递推过程中
    //倒着推
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            dp[i][j] = INT_MAX;
            for(int k = 0; k < m; k++){
                if(ring[k] == key[i]){
                    int dis = abs(j - k);
                    int step = min(dis, m - dis);
                    dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                }
            }
        }
    }
    return dp[0][0] + n;
}

//暴力dfs   49 / 302 个通过测试用例 TLE
int res;
void dfs(string &ring, string &key, int p2r, int p2k, int cur, unordered_multimap<char, int> &ch2idx, int m, int n){
    if(p2k == n){
        if(cur < res)res = cur;
    }
    auto pr = ch2idx.equal_range(key[p2k]);
    int prep2r = p2r, precur = cur;
    for(auto iter = pr.first; iter != pr.second; iter++){
        int nextp2r = iter->second, dis = abs(p2r - iter->second);
        cur += min(dis, m - dis);
        cur++;
        p2r = nextp2r;
        p2k++;
        dfs(ring, key, p2r, p2k, cur, ch2idx, m, n);
        p2k--;
        p2r = prep2r;
        cur = precur;
    }
}

int BFfindRotateSteps(string ring, string key) {
    res = INT_MAX;
    unordered_multimap<char, int> ch2idx;
    int m = ring.size();
    int n = key.size();
    for(int i = 0; i < m; i++){
        ch2idx.insert({ring[i], i});
    }
    dfs(ring, key, 0, 0, 0, ch2idx, m, n);
    return res;
}

int main(){
    cout << findRotateSteps("pqwcx","cpqwx") << endl;
}