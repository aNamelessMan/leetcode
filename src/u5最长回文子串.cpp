#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //最简单的想法是一遍遍历，每个点处判断是否是回文并更新max，回文串起始处和终点   O(n^2)
        // 执行用时：44 ms, 在所有 C++ 提交中击败了92.20% 的用户
        // 内存消耗：6.4 MB, 在所有 C++ 提交中击败了95.33% 的用户
        int maxlen = 0, start = 0;
        for(unsigned i = 0; i < s.size(); i++){
            process(i, i, start, maxlen, s.size(), s);
            process(i, i + 1, start, maxlen, s.size(), s);
        }
        return s.substr(start, maxlen);
    }
    void process(int left, int right, int &start, int &maxlen, int strl, string &str){
        while(left >= 0 && right < strl && str[left] == str[right]){
            left --;
            right ++;
        }
        //注意此时长度并非left - right + 1，因为left和right都已经不满足
        if(right - left - 1 > maxlen){
            maxlen = right - left - 1;
            start = left + 1;
        }
    }
};

int main(){
    Solution solution;

    string input = "cbbd";
    string res = solution.longestPalindrome(input);
    cout << res << endl;

}