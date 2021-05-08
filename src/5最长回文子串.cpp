#include<bits/stdc++.h>
using namespace std;

// 执行用时：32 ms, 在所有 C++ 提交中击败了76.53% 的用户
// 内存消耗：13.9 MB, 在所有 C++ 提交中击败了65.79% 的用户
//2021.5.8三刷
string longestPalindrome(string s) {
    int n = s.size(), res = 0;
    string str;
    for(int i = 0; i < n; i++){
        //分别讨论s[i]为对称轴和两个对称轴中左边的情况
        int len = 0;
        while(i - len >= 0 && i + len < n && s[i - len] == s[i + len]){
            len++;
        }
        if(2 * len - 1 > res){
            res = 2 * len - 1;
            str = s.substr(i - len + 1, 2 * len - 1);//记得把起始点退后1，因为len时此时是不满足回文的
        }

        len = 0;
        while(i - len >= 0 && i + len + 1 < n && s[i - len] == s[i + len + 1]){
            len++;
        }
        if(2 * len > res){
            res = 2 * len;
            str = s.substr(i - len + 1, 2 * len);
        }
    }
    return str;
}

// 执行用时：20 ms, 在所有 C++ 提交中击败了90.80% 的用户
// 内存消耗：14 MB, 在所有 C++ 提交中击败了61.59% 的用户
//2021.3.1二刷  中心扩散法
string longestPalindrome(string s) {
    int n = s.size();
    string res;
    for(int i = 0; i < n; i++){
        //回文的两种情况，1该字符为唯一的中间字符2.该字符为两个中间字符中靠左的那个
        int l = i - 1, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        if(r - l - 1 > int(res.size()))
            res = s.substr(l + 1, r - l - 1);
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        if(r - l - 1 > int(res.size()))
            res = s.substr(l + 1, r - l - 1);
    }
    return res;
}

string firstlongestPalindrome(string s) {
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

int main(){
    string input = "cbbd";
    string res = longestPalindrome(input);
    cout << res << endl;

}