//
// Created by 秦俊 on 2023/4/24.
//
//
// Created by 秦俊 on 2023/4/24.
//
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
//    注意到 1. 前缀相同，字符串越长字典序越靠后 2.字典序越靠后的字符串首字母一定越靠后
//note3/4 : Since the limits are high, we need an efficient data structure. / Use suffix array.
//双指针？
    string  lastSubstring(string s){
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while(j + k < n){
            if(s[i + k] == s[j + k]){
                k++;
            }else if(s[i + k] > s[j + k]){
//                j++;
//              当s[i + k] > s[j + k]时，以s[j]开头的字符串已经不可能大于以s[i]开头的字符串了，只能尝试下一个字符开头
                j = j + k + 1;
                k = 0;
            }else{
//                i = j;
//                j = j + 1;
//              遍历到此处时，s[j]开头的字符串大于s[i]开头的字符串，且s[i + 0..k]开头的字符串一定小于s[j + 0..k]因此排除跳过
                i = max(j, i + k + 1);
                j = i + 1;
                k = 0;
            }
        }
        return s.substr(i, n - i);
    }
//note2 : The answer is always a suffix of the given string. 13/32
    string lastSubstringNormal(string s){
        int n = s.size();
        string res = "";
        for(int i = 1; i < n; i++){
            res = max(res, s.substr(n - i, i));
        }
        return res;
    }
//note1 : Assume that the answer is a sub-string from index i to j. If you add the character at index j+1 you get a better answer.
//    10/32
    string lastSubstringDP(string s){
        int n = s.size();
        vector<string> dp(n, "");
        dp[0] = s[0];
        unordered_map<char, set<int> > idxs;
        idxs[s[0]].insert(0);
        int curMaxChar = s[0];
        for(int i = 1; i < n; i++){
            if(s[i] > curMaxChar){
                dp[i] = s[i];
                curMaxChar = s[i];
            }else{
                dp[i] = dp[i - 1];
                for(auto &idx : idxs[curMaxChar]){
                    dp[i] = max(dp[i], s.substr(idx, i - idx + 1));
                }
            }
            idxs[s[i]].insert(i);
        }
        return dp[n - 1];
    }
};

int main(){
    Solution s;
    cout << s.lastSubstring("leetcode") << endl;
}

