#include <bits/stdc++.h>
using namespace std;

// 执行用时：208 ms, 在所有 C++ 提交中击败了11.08% 的用户
// 内存消耗：14.1 MB, 在所有 C++ 提交中击败了5.02% 的用户
//2021.3.19 注意x*可以匹配空字符
bool isMatch(string s, string p) {
    if(p.empty()){
        return s.empty();
    }
    if(p.size() == 1){
        if(p[0] == '.')return s.size() == 1;
        else{
            return s.size() == 1 && s[0] == p[0];
        }
    }
    //运行到此处p.size()一定大于等于2
    if(!s.empty()){
        if(p[1] == '*'){
            if(p[0] == '.'){
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }else if(p[0] == s[0]){
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }else{
                return isMatch(s, p.substr(2));
            }
        }else{
            if(p[0] == '.' || p[0] == s[0]){
                return isMatch(s.substr(1), p.substr(1));
            }else{
                return false;
            }
        }
    }
    if(s.empty() && p[1] == '*')return isMatch(s, p.substr(2));
    return false;
}

// 执行用时：700 ms, 在所有 C++ 提交中击败了13.87% 的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了17.58% 的用户
//没做出来。。看的题解

// - 若p为空，若s也为空，返回 true，反之返回 false。

// - 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。

// - 若p的第二个字符不为*，若此时s为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。

// - 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），调用递归函数匹配s和去掉前两个
// 字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回 true，否则s去掉首字母
// （因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。

// - 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，直接进
// 入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，
// 返回 true。再举个例子，比如 s="", p="a*"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true，正确）。


    bool isMatch(string s, string p) {
        /*按p的大小分为 0、1、其余 三种情况，
            1.  p为空必须s也为空
            2.  p大小为1必须s大小也为1  且相等或为'.'
            3.  根据p第二个字符是否为'*'分为两种情况    不为'*'必须首字符相等然后递归下个字符
                                                   (s必须不为空)为'*'首字符必须相同，之后不断取s[1,...]和p[2,...]递归    为真则返回真
                                                   最后如果都未返回，递归s和p[2,...]
        */
        if(p.empty()){
            if(s.empty())return true;
            else return false;
        }
        if(p.size() == 1){
            if(s.size() == 1 && (p[0] == s[0] || p[0] == '.'))
                return true;
            else
                return false;
        }
        if(p[1] != '*'){
            if(s.empty())return false;
            else
                return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
int main(){
    cout << isMatch("aaa", "ab*a*c*a") << endl;
}