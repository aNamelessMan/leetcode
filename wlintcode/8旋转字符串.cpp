#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 47.00% 的提交!
void rotateString(string &str, int offset) {
    if(str.empty())return;
    string res;
    offset %= str.size();

    for(int i = str.size() - offset; i < str.size(); i++){
        res += str[i];
    }
    for(int i = 0; i < str.size() - offset; i++){
        res += str[i];
    }
    str = res;
}

int main(){
    cout << 1 << endl;
}