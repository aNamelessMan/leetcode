#include<bits/stdc++.h>
using namespace std;

//没写出来，好无聊的题，懒得写了
vector<string> wrongfullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int n = words.size();
    int i = 1, start, l;
    while(i < n){
        i--;
        start = i, l = 0;
        l += words[start].size();
        i++;
        while(l <= maxWidth && i < n){
            l += words[i].size();
            l++;
            i++;
        }//注意第i - 1个是不能放进本行的，因为加上它后长度超出了
        if(i == n && l <= maxWidth)break;
        l -= (words[i - 1].size() + 1);//注意取出的长度包括一个空格
        int cnt = i - start - 1;//本轮要添加的单词数，间隔数为cnt - 1
        int empty = maxWidth - l, avg = empty / (cnt - 1), remain = empty % (cnt - 1);
        string tmp = words[start];
        for(int j = start + 1; j < start + remain + 1; j++){
            tmp += string(avg + 2, ' ');
            tmp += words[j];
        }
        for(int j = start + remain + 1; j < start + cnt; j++){
            tmp += string(avg + 1, ' ');
            tmp += words[j];
        }
        res.push_back(tmp);
        if(i == n)start += cnt; 
    }
    string tmp = words[start];
    if(start == n - 1)tmp += " ";
    for(int j = start + 1; j < n; j++){
        tmp += " ";
        tmp += words[j];
    }
    res.push_back(tmp);
    return res;
}

int main(){
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = wrongfullJustify(words, 16);
    return 0;
}