#include <bits/stdc++.h>
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了58.73% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了58.67% 的用户
char firstUniqChar(string s) {
    unordered_map<char, int> m;
    for(auto ch:s){
        m[ch]++;
    }
    for(auto ch:s){
        if(m[ch] == 1)return ch;
    }
    return ' ';
}

int main(){
    cout << "print sth." << endl;
}