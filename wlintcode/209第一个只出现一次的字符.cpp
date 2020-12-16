#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 67.20% 的提交!
char firstUniqChar(string &str) {
    unordered_map<char, int> uni;
    unordered_set<char> notuni;
    for(int i = 0; i < str.size(); i++){
        if(notuni.count(str[i]))continue;
        if(uni.count(str[i])){
            uni.erase(uni.find(str[i]));
            notuni.insert(str[i]);
        }else{
            uni.insert({str[i],i});
        }
    }
    char res;
    int r = INT_MAX;
    for(auto iter = uni.begin(); iter != uni.end(); iter++){
        if(iter->second < r){
            r = iter->second;
            res = iter->first;
        }
    }
    return res;
}

int main(){
    string s = "abaccdeff";
    firstUniqChar(s);
    cout << 1 << endl;
}