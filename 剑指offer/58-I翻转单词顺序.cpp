#include <bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了51.99% 的用户
// 内存消耗：7.8 MB, 在所有 C++ 提交中击败了79.28% 的用户
//相比下面优化了下空间，不需要栈了，但是时间会变慢虽然复杂度一样
string reverseWords2(string s) {
    string res, t;
    istringstream str(s);
    while(str >> t){
        reverse(t.begin(), t.end());
        res += t;
        res += " ";
    }
    if(!res.empty())res.pop_back();//注意pop_back在空字符串上仍然可以但不应该调用，因此应该在调用前判断是否为空
    //否则调用后res的size变成-1，用empty判断会显示不为空

    reverse(res.begin(), res.end());
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了50.16% 的用户
string reverseWords1(string s) {
    string res, t;
    istringstream str(s);
    stack<string> stk;
    while(str >> t){
        stk.push(t);
    }
    while(!stk.empty()){
        res += stk.top();
        res += " ";
        stk.pop();
    }
    if(!res.empty())res.pop_back();
    return res;
}

int main(){
    cout << reverseWords1("") << endl;
    cout << reverseWords2("") << endl;
}