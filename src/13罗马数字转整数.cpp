#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了28.07% 的用户
// 内存消耗：7.8 MB, 在所有 C++ 提交中击败了40.29% 的用户
// 21.5.13二刷
int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    //从左往右走，并记录遇到的最大值，如果便利到的值小于最大值，则减去这个值
    int curmax = m[s[0]], n = s.size(), res = 0;
    for(int i = n - 1; i >= 0; i--){
        if(m[s[i]] < curmax){
            res -= m[s[i]];
        }else{
            curmax = m[s[i]];
            res += curmax;
        }
    }
    return res;
}

// 执行用时：40 ms, 在所有 C++ 提交中击败了32.51% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了53.28% 的用户
int fitstromanToInt(string s) {
    unordered_map<char, int> r2a;
    r2a['I'] = 1;
    r2a['V'] = 5;
    r2a['X'] = 10;
    r2a['L'] = 50;
    r2a['C'] = 100;
    r2a['D'] = 500;
    r2a['M'] = 1000;
    int res = 0;
    for(unsigned i = 0; i < s.size(); i++){
        if(i == s.size() - 1){res += r2a[s[s.size() - 1]]; i++;}
        else if(r2a[s[i]] < r2a[s[i + 1]]) {
            res -= r2a[s[i]];
            i++;
            res += r2a[s[i]];
        }else{
            res += r2a[s[i]];
        }
    }
    return res;
}

int main(){
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
}