#include<bits/stdc++.h>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    if(s.empty())return -1;
    int res = 0;
    set<char> ch;
    unordered_map<char, int> minidx;
    unordered_map<char, int> maxidx;
    for(int i = 0; i < (int)s.size(); i++){
        if(!ch.count(s[i])){
            ch.insert(s[i]);
        }
        if(!minidx.count(s[i])){
            minidx.insert({s[i], i});
        }
        maxidx[s[i]] = i;
    }
    for(auto &c:ch){
        if(maxidx[c] - minidx[c] > res)res = maxidx[c] - minidx[c];
    }
    if(res == 0)return -1;
    return res - 1;
}

int main(){
    cout << 1 << endl;
}