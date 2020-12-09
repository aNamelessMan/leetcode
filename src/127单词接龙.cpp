#include<bits/stdc++.h>
using namespace std;
// 执行用时：1360 ms, 在所有 C++ 提交中击败了12.90% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了58.57% 的用户
//bfs即可，想了好久，因为没怎么写过，怎么记录层数想了好久
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    if(n == 0)return 0;
    int sn = wordList[0].size();

    vector<bool> path(wordList.size(), false);
    unordered_map<string, int>bfs;//用来记录每个节点所在层数
    bfs[beginWord] = 1;

    queue<string> q;
    q.push(beginWord);
    
    while(!q.empty()){
        string pre = q.front();
        if(pre == endWord)return bfs[pre];
    
        for(int i = 0; i < n; i++){
            if(path[i])continue;
            int d = 0;
            for(int j = 0; j < sn; j++){
                if(pre[j] != wordList[i][j]){
                    d++;
                    if(d > 1)break;
                }
            }
            if(d == 1){
                bfs[wordList[i]] = bfs[pre] + 1;
                path[i] = true;
                q.push(wordList[i]);
            }
        }
        q.pop();
    }

    return 0;
}

int main(){
    vector<string> wordList({"hot","dot","dog"});
    cout << ladderLength("hot", "dot", wordList) << endl;
}