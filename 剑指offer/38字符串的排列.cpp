#include <bits/stdc++.h>
using namespace std;

// 执行用时：216 ms, 在所有 C++ 提交中击败了15.29% 的用户
// 内存消耗：59.3 MB, 在所有 C++ 提交中击败了4.97% 的用户
void dfs(vector<string> &res, unordered_set<int> &cs, string &s, string &t){
    if(s.size() == t.size()){
        res.push_back(t);
        return;
    }
    unordered_set<char> visited;//在一个位置上相同的字符只能出现一次
    for(int i = 0; i < int(s.size()); i++){
        if(cs.count(i) || visited.count(s[i]))continue;
        visited.insert(s[i]);

        t += s[i];
        cs.insert(i);
        dfs(res, cs, s, t);
        cs.erase(i);
        t.pop_back();
    }
}

vector<string> permutation(string s) {
    vector<string> res;
    string t;
    unordered_set<int> cs;
    dfs(res, cs, s, t);
    return res;
}

int main(){
    cout << "print sth." << endl;
}