#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.6 MB, 在所有 C++ 提交中击败了10.43% 的用户
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int n = words.size();
    int i = 1, start = 0, l;
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
        string tmp;
        if(cnt == 1){
            tmp = words[start];
        }else{
            int empty = maxWidth - l, avg = empty / (cnt - 1), remain = empty % (cnt - 1);
            tmp = words[start];
            for(int j = start + 1; j < start + remain + 1; j++){
                tmp += string(avg + 2, ' ');
                tmp += words[j];
            }
            for(int j = start + remain + 1; j < start + cnt; j++){
                tmp += string(avg + 1, ' ');
                tmp += words[j];
            }
        }

        while((int)tmp.size() < maxWidth){
            tmp += ' ';
        }

        res.push_back(tmp);
        if(i == n)start += cnt; 
    }
    string tmp = words[start];
    for(int j = start + 1; j < n; j++){
        tmp += " ";
        tmp += words[j];
    }

    while((int)tmp.size() < maxWidth){
        tmp += ' ';
    }

    res.push_back(tmp);
    return res;
}

int main(){
    vector<string> words = {"a"};
    fullJustify(words, 1);
}