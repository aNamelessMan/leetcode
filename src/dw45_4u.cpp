#include <bits/stdc++.h>
using namespace std;

//dfs   63 / 65 个通过测试用例  TLE
static bool comp(const vector<int> &v1, const vector<int> &v2){
    return v1[1] < v2[1];//按会议结束时间从早到晚排序
}
    
void dfs(int start, int n, vector<vector<int>>& events, vector<vector<int>>& pres, int cur, int k, int &res){
    if(k == 0 || start == n)return;
    for(int i = start; i < n; i++){
        if(!pres.empty() && events[i][0] <= pres.back()[1])continue;
        
        cur += events[i][2];
        pres.push_back(events[i]);
        res = max(res, cur);
        dfs(i, n, events, pres, cur, k - 1, res);
        cur -= events[i][2];
        pres.pop_back();
    }
}
    
int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), comp);
    vector<vector<int>> pres;
    int res = 0, n = events.size();
    dfs(0, n, events, pres, 0, k, res);
    return res;
}

int main(){
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    maxValue(events, 2);
}