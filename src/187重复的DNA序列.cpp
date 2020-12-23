#include<bits/stdc++.h>
using namespace std;

// 执行用时：100 ms, 在所有 C++ 提交中击败了72.79% 的用户
// 内存消耗：23.3 MB, 在所有 C++ 提交中击败了27.43% 的用户
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> cnt;
    int n = s.size();
    for(int i = 0; i <= n - 10; i++){
        cnt[s.substr(i, 10)]++;
    }
    vector<string> res;
    for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
        if(iter->second > 1)res.push_back(iter->first);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}