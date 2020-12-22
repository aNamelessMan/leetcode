#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    vector<string> p{beginWord};
    queue<vector<string>> paths;
    paths.push(p);
    int level = 1, minLevel = INT_MAX;//level是循环中当前路径的长度
    unordered_set<string> words;//记录路径中新增的词
    while (!paths.empty()) {
        auto t = paths.front(); paths.pop();
        if (t.size() > level) {
            for (string w : words) dict.erase(w);
            words.clear();
            level = t.size();
            if (level > minLevel) break;
        }
        string last = t.back();
        for (int i = 0; i < last.size(); ++i) {//尝试替换路径中最后一个字符串中的每个字符
            string newLast = last;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                newLast[i] = ch;
                if (!dict.count(newLast)) continue;
                words.insert(newLast);
                vector<string> nextPath = t;
                nextPath.push_back(newLast);
                if (newLast == endWord) {
                    res.push_back(nextPath);
                    minLevel = level;
                } else paths.push(nextPath);
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}