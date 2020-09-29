#include<bits/stdc++.h>
using namespace std;
//34 / 36 个通过测试用例  TLE
bool isAna(string &s, multiset<char> sp, unsigned b, unsigned e){
    for(;b < e;b++){
        auto iter = sp.find(s[b]);
        if(iter != sp.end() ) sp.erase(iter);
        else return false;
    }
    return true;
}
vector<int> BFfindAnagrams(string s, string p) {
    vector<int> res;
    multiset<char> sp;
    for(auto &c:p){
        sp.insert(c);
    }
    for(unsigned i = 0; i < s.size(); i++){
        if(isAna(s, sp, i, i + p.size()))res.push_back(i);
    }
    return res;
}
// 执行用时：28 ms, 在所有 C++ 提交中击败了73.85% 的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了98.38% 的用户
//滑动窗口
vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> s_f(26, 0);
    vector<int> p_f(26, 0);
    unsigned l, r;
    if(s.size() < p.size())return res;
    for(l = 0, r = 0; r < p.size(); r++){
        p_f[p[r] - 'a']++;
        s_f[s[r] - 'a']++;
    }
    if(p_f == s_f)res.push_back(l);
    
    for(;r < s.size();){
        s_f[s[r++] - 'a']++;
        s_f[s[l++] - 'a']--;
        if(p_f == s_f)res.push_back(l);
    }
    return res;
}

int main(){
    vector<int> res = findAnagrams("", "aa");
    for(auto &i:res){
        cout << i << ",";
    }
    cout << endl;
}