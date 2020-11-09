#include<bits/stdc++.h>
using namespace std;
// 执行用时：140 ms, 在所有 C++ 提交中击败了5.02% 的用户
// 内存消耗：628.9 MB, 在所有 C++ 提交中击败了5.00%
int strStr(string haystack, string needle) {
    if(needle.empty())return 0;
    int m = haystack.size(), n = needle.size();
    for(int i = 0; i < m; i++){
        if(haystack.substr(i, n) == needle)return i;
    }
    return -1;
}

//c++内置函数
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了28.11% 的用户
int builtinstrStr(string haystack, string needle) {
    return haystack.find(needle);
}

//暴力解法 78 / 78 个通过测试用例   TLE
int BFstrStr(string haystack, string needle) {
    if(needle.empty())return 0;
    int m = haystack.size(), n = needle.size();
    for(int i = 0; i < m; i++){
        int j;
        for(j = 0; j < n; j++){
            if(haystack[i + j] != needle[j])break;
        }
        if(j == n)return i;
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}