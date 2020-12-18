#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了35.84% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了5.03% 的用户
char findTheDifference(string s, string t) {
    //先用hash表将s中的字符计数，再遍历t将前面的hash表键值对应减一，减到-1就是所求值
    unordered_map<char, int> m;
    for(char c:s){
        m[c]++;
    }
    for(char c:t){
        m[c]--;
        if(m[c] == -1)return c;
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}