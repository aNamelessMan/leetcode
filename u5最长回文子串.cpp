#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string BFlongestPalindrome(string s) {//暴力解法，时间超出限制TLE，算法简单但是错了好多次。。
        int bd = 0;
        int maxlen = 0;
        int tmplen = 0;
        string tmp;
        string res;
        if(s.size() == 1)
            return s;

        for(int i = 0;i != s.size();++i){

                tmp = s[i];
                tmplen += 1;
                bd = min(i,(int)(s.size() - 1 - i)) + 1;
                for(int j = 1;j != bd;++j){
                    if(s[i-j] == s[i+j]){
                        tmplen += 2;
                        tmp = s[i - j] + tmp + s[i + j];
                    }else{
                        break;
                    }
                }
            if(tmplen > maxlen){
                res = tmp;
                maxlen = tmplen;
            }
            tmplen = 0;

            if(i != s.size() - 1 && s[i] == s[i + 1]){
                 tmp =  s[i];
                tmp += s[i+1];
                tmplen += 2;
                bd = min(i,(int)(s.size() - 2 - i)) + 1;
                for(int j = 1;j != bd;++j){
                    if(s[i-j] == s[i+j+1]){
                        tmplen += 2;
                        tmp = s[i - j] + tmp + s[i + j+1];
                    }else{
                        break;
                    }
                }
             if(tmplen > maxlen){
                res = tmp;
                maxlen = tmplen;
            }
            tmplen = 0;
            }

        }

        return res;
    }
};

int main(){
    Solution solution;

    string input = "cbbd";
    string res = solution.BFlongestPalindrome(input);
    cout << res << endl;

}