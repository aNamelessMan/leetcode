#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：3.3 MB, 在所有 C++ 提交中击败了100.00% 的用户
int minDistance(string word1, string word2) {
    int dp[word1.size() + 1][word2.size() + 1];
    //dp[0][0] = 0;
    for(int i = 0; i <= word1.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= word2.size(); i++){
        dp[0][i] = i;
    }
    for(int i  = 1; i <= word1.size(); i++){
        for(int j  = 1; j <= word2.size(); j++){
            if(word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
            else    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    return dp[word1.size()][word2.size()];
}
int main(){
    string input;
    while(cin >> input){
        char str1[101], str2[101];
        memset(str1, 0, 101 * sizeof(char));
        memset(str2, 0, 101 * sizeof(char));
        int i = 0, n = input.size(), j = 0;
        while(input[i] != ',' && i < n){
            str1[i] = input[i];
            i++;
        }
        i++;
        while(i < n){
            str2[j] = input[i];
            i++;
            j++;
        }
        string s1(str1);
        string s2(str2);
        cout << minDistance(s1, s2) << endl;
    }
}