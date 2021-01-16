#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了86.19% 的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了96.07% 的用户
string getHint(string secret, string guess) {
    int n = secret.size(), a = 0;
    unordered_map<int, int> cnt1;
    unordered_map<int, int> cnt2;
    for(int i = 0; i < n; i++){
        if(secret[i] == guess[i])a++;
        else{
            cnt1[secret[i]]++;
            cnt2[guess[i]]++;
        }
    }
    int b = 0;
    for(auto i = cnt2.begin(); i != cnt2.end(); i++){
        b += min(i->second, cnt1[i->first]);
    }
    return to_string(a) + "A" + to_string(b) + "B";
}

int main(){
    cout << "print something." << endl;
}