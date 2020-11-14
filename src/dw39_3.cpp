#include<bits/stdc++.h>
using namespace std;

void dfs(int cur, int no, int &res, bool canback, int a, int b, int x, unordered_set<int> &fbd){
    if(cur < 0)return;
    if(cur == x){
        res = min(res, no);
        return;
    }
    // if(cur > x && a >= b){
    //     if(canback){
    //         if(cur - b > x)
    //             return;
    //     }
    //     else
    //         return;
    // }
    if(canback && cur - b >= 0 && !fbd.count(cur - b)){
        dfs(cur - b, no + 1, res, !canback, a, b,x, fbd);
    }
    if(!fbd.count(cur + a)){
        dfs(cur + a, no + 1, res, canback, a, b,x, fbd);
    }
}

int wrongminimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> fbd;
    for(auto& i:forbidden)fbd.insert(i);
    int res = INT_MAX;
    dfs(0, 0, res, true, a, b,x, fbd);
    if(res == INT_MAX)return -1;
    return res;
}

int main(){
    // vector<int> fbd({14,4,18,1,15});
    vector<int> fbd({8,3,16,6,12,20});
    cout << wrongminimumJumps(fbd, 15, 13, 11) << endl;
}