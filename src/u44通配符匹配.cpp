#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了90.47% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了88.13% 的用户
bool isMatch(string s, string p) {
    //i和j分别记录当前遍历的s和p的下标
    //istar是*匹配的最后一个值的下标， j是
    int m = s.size(), n = p.size(), istar = -1, jstar = -1, i = 0, j = 0;
    while(i < m){
        if(j < n && (s[i] == p[j] || p[j] == '?')){
            i++;
            j++;
        }else if(j < n && p[j] == '*'){
            istar = i;
            jstar = j;
            j++;
        }else if(istar >= 0){
            i = istar + 1;
            istar++;
            j = jstar + 1;
        }else{
            return false;
        }
    }
    while(j < n && p[j] == '*')j++;
    return j == n;
}

//递归解法  1708 / 1811 个通过测试用例  TLE
//复杂度是O('*'的个数   *   s.size())
//用preprocess优化了每段重复的'*'，但是多段'*'还是会超时
bool preprocessed = false;
void preprocess(string &p){
    if(preprocessed)return;
    int n = p.size();
    string res;
    for(int i = 0; i < n; i++){
        if(p[i] != '*')res += p[i];
        else{
            while(i < n && p[i] == '*'){
                i++;
            }
            res += '*';
            if(i < n)res += p[i];
        }
    }
    p = res;
    preprocessed = true;
}
bool BFisMatch(string s, string p) {
    preprocess(p);
    if(p.empty())return s.empty();
    if(p == "*")return true;
    if(p == "?")return s.size() == 1;
    if(p.size() == 1)return p == s;

    char t = p[0];
    if(t == '*'){
        if(s.empty())return BFisMatch(s, p.substr(1, p.size() - 1));
        for(int i = 0; i < (int)s.size(); i++){
            if(BFisMatch(s.substr(i, s.size() - i), p.substr(1, p.size() - 1)))
                return true;
        }
        return false;
    }
    if(s.empty())return false;
    if(t == '?')return BFisMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
    if(t == s[0])return BFisMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
    return false;
}

int main(){
    string p = "a*******b";
    //preprocess(p);
    cout << p << endl;
    //cout << isMatch("", "******") << endl;
    cout << BFisMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb","b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
) << endl;
}