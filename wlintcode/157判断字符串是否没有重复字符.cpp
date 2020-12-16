#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 10.40% 的提交!
bool isUnique(string &str) {
    set<char> s;
    for(auto &ch:str){
        if(s.count(ch))return false;
        s.insert(ch);
    }
    return true;
}

int main(){
    cout << 1 << endl;
}