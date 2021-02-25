#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了97.57% 的用户
//就是leetcode第65题，当时写的很繁琐，这次学习了一下别人的写法
bool isNumber(string s) {
    int n = s.size();
    int l = 0, h = n - 1;
    while(s[l] == ' ' && l < h)l++;
    while(s[h] == ' ' && h > l)h--;

    bool seennum = false, seendot = false, seene = false;
    for(int i = l; i <= h; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            seennum = true;
        }else if(s[i] == '.'){
            if(seendot || seene)return false;//e或.之后都不能出现.
            seendot = true;
        }else if(s[i] == '+' || s[i] == '-'){//只能出现在开头或e之后
            if(i != l && s[i - 1] != 'e' && s[i - 1] != 'E'){
                return false;
            }
        }else if(s[i] == 'e' || s[i] == 'E'){
            if(seene || !seennum)return false;//e前面必须要有数字
            seene = true;
            seennum = false;//e之后必须要有数字
        }else{
            return false;
        }
    }
    return seennum;//防止以e结尾，其他情况到这里都应该返回true
}

int main(){
    cout << isNumber(" -54.53061") << endl;
}