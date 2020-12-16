#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 12.60% 的提交!
int mostFrequentlyAppearingLetters(string &str) {
    if(str.empty())return 0;
    map<char, int> m;
    for(auto &ch:str)m[ch]++;
    int res = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second > res)res = i->second;
    }
    return res;
}

int main(){
    string str = "qtlttMM";
    mostFrequentlyAppearingLetters(str);
    cout << 1 << endl;
}