#include<bits/stdc++.h>
using namespace std;
// 执行用时：40 ms, 在所有 C++ 提交中击败了32.51% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了53.28% 的用户
int romanToInt(string s) {
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