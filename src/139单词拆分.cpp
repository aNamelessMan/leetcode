#include<bits/stdc++.h>
using namespace std;

// 执行用时：72 ms, 在所有 C++ 提交中击败了5.34% 的用户
// 内存消耗：14.9 MB, 在所有 C++ 提交中击败了7.05% 的用户
bool wordBreak(string &s, vector<string>& wordDict, int i, int j, vector<vector<int>> &dp, unordered_set<string> &dict){
    /*基本情况
    1.字符串为空    返回true    这个实现里可以去掉
    2.字符串只有一个字符，不能继续拆    返回dict.count(s.substr(i, 1))
    3.如果dict里有当前字符串，直接设置dp返回true

    4.其余情况  迭代所有把当前字符串拆分两个字符串并在这两个字符串递归判断，都可拆分即可拆分
    */
    //if(j < i)return true;
    if(i == j){
        dp[i][i] = dict.count(s.substr(i, 1));
        return dp[i][i];
    }
    if(dp[i][j] != -1)return dp[i][j];
    if(dict.count(s.substr(i, j - i + 1))){
        dp[i][j] = 1;
        return true;
    }

    for(int k = i + 1; k <= j; k++){//k是分割处字符包含在后一个字符中
        //递归判断s[i, k - 1]和s[k, j]
        if(wordBreak(s, wordDict, i, k - 1, dp, dict)){
            dp[i][k - 1] = 1;
            if(wordBreak(s, wordDict, k, j, dp, dict)){
                dp[k][j] = 1;
                dp[i][j] = 1;
                return true;
            }else{
                dp[k][j] = 0;
            }
        }else{
            dp[i][k - 1] = 0;
        }
    }
    dp[i][j] = 0;

    return false;
} 

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    if(n == 0)return true;
    unordered_set<string> dict;
    for(auto &str:wordDict)dict.insert(str);

    vector<vector<int>> dp(n, vector<int>(n, -1));//-1代表未初始化，0/1表示s[i, j]是否可以拆分

    return wordBreak(s, wordDict, 0, n - 1, dp, dict);
}

int main(){
    cout << 1 << endl;
}