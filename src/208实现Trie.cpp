#include<bits/stdc++.h>
using namespace std;

// 执行用时：68 ms, 在所有 C++ 提交中击败了68.13% 的用户
// 内存消耗：27.9 MB, 在所有 C++ 提交中击败了96.86% 的用户
class Trie {
public:
    struct node{
        vector<node*> children;
        char val;
        bool has = false;//表示从根节点到此处形成的字符串是否被插入过
        node(char ch):val(ch){}
    };

    /** Initialize your data structure here. */
    Trie():root(' ') {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0, n = word.size();
        node *cur = &root;
        while(i < n){
            bool has = false;
            for(node *c: cur->children){
                if(c->val == word[i]){
                    cur = c;
                    i++;
                    has = true;
                    break;
                }
            }
            if(has){
                continue;
            }else{
                node *t = new node(word[i]);
                (cur->children).push_back(t);
                cur = t;
                i++;
            }
        }
        cur->has = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0, n = word.size();
        node *cur = &root;
        while(i < n){
            bool has = false;
            for(node *c: cur->children){
                if(c->val == word[i]){
                    cur = c;
                    i++;
                    has = true;
                    break;
                }
            }
            if(has){
                continue;
            }else{
                return false;
            }
        }
        return cur->has;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0, n = prefix.size();
        node *cur = &root;
        while(i < n){
            bool has = false;
            for(node *c: cur->children){
                if(c->val == prefix[i]){
                    cur = c;
                    i++;
                    has = true;
                    break;
                }
            }
            if(has){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
private:
    node root;
};

// 执行用时：1032 ms, 在所有 C++ 提交中击败了5.22% 的用户
// 内存消耗：23.2 MB, 在所有 C++ 提交中击败了98.45% 的用户
class BFTries{
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
};

int main(){
    cout << 1 << endl;
}