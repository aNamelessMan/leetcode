#include<bits/stdc++.h>
using namespace std;

// 执行用时：260 ms, 在所有 C++ 提交中击败了13.80% 的用户
// 内存消耗：73.2 MB, 在所有 C++ 提交中击败了33.95% 的用户
class WordDictionary {

typedef struct node{
    unordered_map<char, node*> points;
    bool end = false;//表示是否有到此结束的字符串
} node;

public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        node* iter = root;
        for(int i = 0; i < n; i++){
            if(iter->points[word[i]] == nullptr){
                iter->points[word[i]] = new node;
            }
            iter = iter->points[word[i]];
        }
        iter->end = true;
    }
    
    bool search(const string &word, node* iter){
        if(word.empty())return iter->end;//注意搜索过程中不能修改points，也就是不能有下标操作，否则会添加空指针
        if(word[0] != '.'){
            if(iter->points.count(word[0]) == 0)return false;
            else return search(word.substr(1), iter->points[word[0]]);
        }else{
            for(auto i = iter->points.begin(); i != iter->points.end(); i++){
                if(search(word.substr(1), i->second))return true;
            }
            return false;
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
private:
    node* root = new node;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    cout << 1 << endl;
}