#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了32.07% 的用户
//2021.4.14二刷
string getHint(string secret, string guess) {
    int n = secret.size(), A = 0, B = 0;
    unordered_map<char, int> str1, str2;
    for(int i = 0; i < n; i ++){
        if(secret[i] == guess[i])A++;
        else{
            str1[secret[i]]++;
            str2[guess[i]]++;
        }
    }
    for(char ch = '0'; ch <= '9'; ch++){
        B += min(str1[ch], str2[ch]);
    }
    return to_string(A) + "A" + to_string(B) + "B";
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了86.19% 的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了96.07% 的用户
string firstgetHint(string secret, string guess) {
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