#include<bits/stdc++.h>
using namespace std;
//没写出来 Wroooooooooooooooong!
bool isSmaller(const string a, const string b){
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] == b[i])continue;
        else if(a[i] > b[i])return false;
        else return true;
    }
    return false;
}
char addi(char c, int a){
    if(c + a > '9'){
        return c + a - 10;
    }else{
        return c + a;
    }
}
string rot(string s, int b){
    string r;
    for(int i = b; i < (int)s.size(); i++){
        r += s[i];
    }
    for(int i = 0; i < b; i++){
        r += s[i];
    }
    return r;
}

string findLexSmallestString(string s, int a, int b) {
    string res = s;
    string t = res;
    for(int j = 0; j < 10; j++){
        for(int i = 1; i < (int)s.size(); i+=2){
            t[i] = addi(t[i], a);
        }
        if(isSmaller(t, res))res = t;
    }
    for(int i = 0; i < b * (int)s.size() + 10; i++){
        string t = rot(res, b);
        for(int j = 0; j < 10; j++){
            for(int i = 1; i < (int)s.size(); i+=2){
                t[i] = addi(t[i], a);
            }
            if(isSmaller(t, res))res = t;
        }
    }

    return res;
}

int main(){
    // cout << addi('9', 2) << endl;
    // cout << isSmaller("345", "346") << endl;
    // cout << rot("a", 1) << endl;
    cout << findLexSmallestString("5525", 9, 2) << endl;
    cout << findLexSmallestString("74", 5, 1) << endl;
    cout << findLexSmallestString("0011", 4, 2) << endl;
    cout << findLexSmallestString("43987654", 7, 3) << endl;
}