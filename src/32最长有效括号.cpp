#include<bits/stdc++.h>
using namespace std;
// 执行用时：1420 ms, 在所有 C++ 提交中击败了5.13% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了85.12% 的用户
//有效括号需要当前子串中左括号数量大于右括号数量
int longestValidParentheses(string s) {
    if(s.empty())return 0;
    int maxlen = 0;
    //int start = 0;
    for(int i = 0; i < (int)s.size() - 1; i++){
        if(s[i] == ')')continue;
        int l = 1, r = 0;
        for(int j = i + 1; j < (int)s.size(); j++){
            if(s[j] == '(')l++;
            else r++;
            if(r > l)break;//如果右多余左坑定无效
            else if(r == l){//左右相等是一个有效括号串
                int len = j - i + 1;
                if(len > maxlen){
                    //start = i;
                    maxlen = len;
                }
            }//其余情况继续循环
        }
    }
    return maxlen;
}

int main(){
    cout << longestValidParentheses("(()") << endl;
    cout << longestValidParentheses(")()())") << endl;
}