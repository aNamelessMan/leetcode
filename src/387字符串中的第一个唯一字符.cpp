#include<bits/stdc++.h>
using namespace std;

// 执行用时：104 ms, 在所有 C++ 提交中击败了51.60% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了20.91% 的用户
int firstUniqChar(string s) {
    unordered_map<char, int> cs;
    int n = s.size();
    for(char c:s){
        cs[c]++;
    }
    for(int i = 0; i < n; i++){
        if(cs[s[i]] == 1)return i; 
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}