#include<bits/stdc++.h>
using namespace std;

// 执行用时：704 ms, 在所有 C++ 提交中击败了32.71% 的用户
// 内存消耗：36.6 MB, 在所有 C++ 提交中击败了31.99% 的用户
//暴力解法
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    unordered_map<string, int> wcnt;
    for(auto &str:words){
        wcnt[str]++;
    }
    int m = s.size(), n = words.size(), l = words[0].size();
    for(int i = 0; i <= m - n * l; i++){
        unordered_map<string, int> cnt;
        for(int j = 0; j < n; j++){
            if(!wcnt[s.substr(i + j * l, l)])break;
            cnt[s.substr(i + j * l, l)]++;
        }
        int k = 0;
        for(k = 0; k < n; k++){
            if(cnt[words[k]] != wcnt[words[k]])break;
        }
        if(k == n)res.push_back(i);
    }
    return res;
}

int main(){
    vector<string> words({"word","good","best","good"});
    findSubstring("wordgoodgoodgoodbestword", words);
    cout << 1 << endl;
}