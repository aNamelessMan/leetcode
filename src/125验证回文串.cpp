#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.44% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了11.54% 的用户
bool isPalindrome(string s) {
    string t;
    for(char c:s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            t.push_back(c);
    }
    int n = t.size(), mid = n / 2;
    if(n == 0)return true;
    for(int i = 0; i < mid; i++){
        if(t[i] >= '0' && t[i] <= '9'){
            if(t[i] == t[n - i - 1])continue;
            else return false;
        }
        else if(t[i] >= 'a' && t[i] <= 'z'){
            if(t[i] == t[n - i - 1] || t[i] == t[n - i - 1] + 32)continue;//大写字母的ASCII码比小写字母要小32
            else return false;
        }
        else{
            if(t[i] == t[n - i - 1] || t[i] == t[n - i - 1] - 32)continue;
            else return false;
        }
    }
    return true;
}

int main(){
    cout << 1 << endl;
}