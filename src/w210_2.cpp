#include<bits/stdc++.h>
using namespace std;
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    if(roads.size() == 1)return 1;
    vector<int> num(n, 0);
    int c[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
        }
    }
    for(auto &r:roads){
        num[r[0]]++;
        num[r[1]]++;
        c[r[0]][r[1]] = 1;
        c[r[1]][r[0]] = 1;
    }

    int max = -1;
    for(int i = 0; i < n; i++){//记录下最大路的数量
        if(num[i] > max){
            max = num[i];
        }
    }
    set<int> maxvi;//注意这里的元素不能重复，所以选用set
    //如果使用vector来存，如果所有的城市都是最大路径，那么会存两次，既是最大，也是第二大
    for(int i = 0; i < n; i++){//存下最大路径的idx
        if(num[i] == max){
            maxvi.insert(i);
        }
    }
    for(auto &i:maxvi){//清空最大路径城市
        num[i] = -1;
    }
    int smax = -1;
    for(int i = 0; i < n; i++){//找到路径第二多的数量
        if(num[i] > smax){
            smax = num[i];
        }
    }
    for(int i = 0; i < n; i++){//存下路径第二多的城市
        if(num[i] == smax){
            maxvi.insert(i);
        }
    }
    for(auto &i:num){//回复最大路径的城市
        if(i == -1)i = max;
    }
    
    int res = 0;
    for(auto &i:maxvi){
        for(auto &j:maxvi){
            if(i != j){
                int t = num[i] + num[j] - c[i][j];
                if(t > res)res = t;
            }
        }
    }
    return res;
}

int main(){
    //vector<vector<int>> roads({{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}});
    //vector<vector<int>> roads({{0,1},{0,3},{1,2},{1,3}});
    vector<vector<int>> roads({{1, 0}});
    cout << maximalNetworkRank(2, roads) << endl;
}