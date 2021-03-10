#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了71.47% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了46.80% 的用户
//双指针，2021.3.10自己的写法
string minWindow(string s, string t) {
    int res = INT_MAX, startidx = -1, m = s.size(), n = t.size(), l = 0, r = 0;
    unordered_map<char, int> cset, allc, cnt;
    for(char c:t){
        cset[c]++;
        allc[c]++;
    }//cset是还需要的字符个数，allc是需要的字符个数，cnt是已拥有的字符个数
    while(r < m){
        while(r < m && !cset.empty()){
            if(allc.find(s[r]) != allc.end()){
                if(cset.find(s[r]) != cset.end()){
                    cset[s[r]]--;
                    if(cset[s[r]] == 0){
                        cset.erase(cset.find(s[r]));
                    }
                }
                cnt[s[r]]++;
            }
            r++;
        }
        if(!cset.empty())break;
        while(cset.empty()){
            if(allc.find(s[l]) != allc.end()){
                cnt[s[l]]--;
                if(cnt[s[l]] < allc[s[l]]){
                    cset[s[l]] = 1;
                }
            }
            l++;
        }
        if(r - l + 1 < res){
            startidx = l - 1;
            res = r - l + 1;
        }
    }
    if(startidx == -1)return "";
    else return s.substr(startidx, res);
}

// 执行用时：40 ms, 在所有 C++ 提交中击败了81.52% 的用户
// 内存消耗：16.5 MB, 在所有 C++ 提交中击败了5.04% 的用户
string minWindow(string s, string t) {
    if(t.empty() || s.empty())return "";
    string res;
    unordered_map<char, int> cim;

    for(auto &c: t)cim[c]++;//把t中的每一个字符计数
    int l = 0, r = 0, cnt = 0, minlen = INT_MAX;

    for(r = 0; r < s.size(); r++){
        if(cnt < t.size()){
            cim[s[r]]--;//r所指字符加入
            if(cim[s[r]] >= 0)cnt++;//如果仍然大于等于0，表示是需要的字符
        }
        while(cnt == t.size()){//字符满足要求后，左边界收缩
            if(minlen > r - l + 1){
                minlen = r - l + 1;
                res = s.substr(l, minlen);
            }
            //左边界收缩
            cim[s[l]]++;
            if(cim[s[l]] > 0)cnt--;//大于0说明去除了一个需要的字符
            ++l;
        }            
    }
    return res;
}

int main(){
    cout << 1 << endl;
}