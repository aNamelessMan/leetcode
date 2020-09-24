#include<bits/stdc++.h>
using namespace std;
//暴力递归解法
// 执行用时：156 ms, 在所有 C++ 提交中击败了50.35% 的用户
// 内存消耗：35.6 MB, 在所有 C++ 提交中击败了11.13% 的用户
//需要考虑n为0及freq全为0时的特殊情况
int pure(vector<int> freq, int n){
    sort(freq.begin(), freq.end(), greater<int>());
    int no = 0;
    for(auto &c: freq){
        if(c)no++;
    }
    if(!no)return 0;
    if(no < n + 1){
        int m = freq[0];
        int maxno = 0;
        for(unsigned i = 0; i < freq.size(); i++){
            if(freq[i] == m)maxno++;
            else break;
        }
        return (n + 1) * (m - 1) + maxno;
    }else{
        for(int i = 0; i < n + 1; i++){
            freq[i]--;
        }
        return n + 1 + pure(freq, n);
    }
}

int BFleastInterval(vector<char>& tasks, int n) {
    if(!n)return tasks.size();
    vector<int> freq(26, 0);
    for(auto &c: tasks){
        freq[c - 'A']++;
    }
    return pure(freq, n);
}
//实际上不需要考虑那么多，当上面解法中的no >= n + 1时
//多出来的随便放在哪两个n+1之间都可以
int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26, 0);
    for (char task : tasks) {
        ++cnt[task - 'A'];
    }
    sort(cnt.begin(), cnt.end());
    int i = 25, mx = cnt[25], len = tasks.size();
    while (i >= 0 && cnt[i] == mx) --i;
    return max(len, (mx - 1) * (n + 1) + 25 - i);
}

int main(){
    vector<char> tasks{'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
    int n = 4;
    cout << leastInterval(tasks, n) << endl;
}