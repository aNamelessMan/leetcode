#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了26.22% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了19.71% 的用户
string reorganizeString(string S) {
    int n = S.size();
    string res;
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> q;
    for(auto c:S)m[c]++;
    for(auto p:m){
        if(p.second > (n + 1) / 2)return "";//只有当某个字符出现次数大于长度一半时才会无法重构
        else q.push({p.second, p.first});
    }
    while(q.size() >= 2){
        auto p1 = q.top();
        q.pop();
        res += p1.second;
        auto p2 = q.top();
        q.pop();
        res += p2.second;

        if(--p1.first > 0)q.push(p1);
        if(--p2.first > 0)q.push(p2);
    }
    if(!q.empty())res += q.top().second;//因为剩下的那个肯定是最后两个字符中出现次数更多的那个，而更多的那个先加到res中，因此末尾是次数少的字符，不会重复
    return res;
}

int main(){
    //cout << reorganizeString("aab") << endl;
}