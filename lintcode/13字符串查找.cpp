#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 52.40% 的提交!
int strStr(string &source, string &target) {
    if(target == "")return 0;
    for(int i = 0; i < source.size(); i++){
        if(source.substr(i, target.size()) == target)return i;
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}