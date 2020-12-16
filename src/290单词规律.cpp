#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了14.02% 的用户
bool wordPattern(string pattern, string s) {
    unordered_map<char, int> patn;//映射每个字符到它第一次出现的下标
    unordered_map<string, int> strm;//映射每个字符到它第一次出现的下标
    istringstream str(s);
    vector<string> strvec;
    string tmp;
    while(str >> tmp){
        strvec.push_back(tmp);
    }
    int m = pattern.size(), n = strvec.size();
    if(m != n)return false;
    for(int i = 0; i < m; i++){
        if(patn.find(pattern[i]) == patn.end())patn[pattern[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(strm.find(strvec[i]) == strm.end())strm[strvec[i]] = i;
    }

    for(int i = 0; i < n; i++){
        if(patn[pattern[i]] != strm[strvec[i]])return false;//判断他们第一次出现时的下标是否相同
    }

    return true;
}

int main(){
    cout << 1 << endl;
}