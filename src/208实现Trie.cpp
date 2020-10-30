#include<bits/stdc++.h>
using namespace std;
// 执行用时：1032 ms, 在所有 C++ 提交中击败了5.22% 的用户
// 内存消耗：23.2 MB, 在所有 C++ 提交中击败了98.45% 的用户
set<string> data;
/** Initialize your data structure here. */
void Trie() {

}
    
/** Inserts a word into the trie. */
void insert(string word) {
    data.insert(word);
}
    
/** Returns if the word is in the trie. */
bool search(string word) {
    if(data.count(word))return true;
    return false;
}
    
/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(string prefix) {
    for(auto &str:data){
        if(str.substr(0, prefix.size()) == prefix)return true;
    }
    return false;
}

int main(){
    cout << 1 << endl;
}