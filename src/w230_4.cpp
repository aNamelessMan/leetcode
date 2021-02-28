#include <bits/stdc++.h>
#include "../dataStruc/vecOps.hpp"
using namespace std;

//没写出来
static bool cmp(const pair<int, double>& p1, const pair<int, double>& p2){
    return p1.second < p2.second;
}

vector<double> wronggetCollisionTimes(vector<vector<int>>& cars) {
    int n = cars.size();
    vector<double> curdv(n, 1.0), curds(n, 1.0);
    vector<pair<int, double>> sdivv(n);//当前时刻本车与它后一辆车的速度差，路程差
    //路程差/时间差最小的车就是下一个会追到的车辆
    //res[n - 1]一定是-1
    vector<double> res(n, -1.0);
    int tc = 0;
    while(1){//终止条件是所有的后车都比前车慢  也就是curdv都是正数
        for(int i = 1; i < n; i++){
            curdv[i] = cars[i][1] - cars[i - 1][1];
            curds[i] = cars[i][0] - cars[i - 1][0];
            sdivv[i] = curdv[i] != 0?make_pair(i, curds[i] / -curdv[i]):make_pair(i, DBL_MAX);
        }
        sort(sdivv.begin(), sdivv.end(), cmp);
        // if(sdivv[n - 1].second < 0)break;
        //找到第一个非负且first不为0
        int k = 0;
        while(k < n){
            if(sdivv[k].second < 0 || sdivv[k].first == 0)k++;
            else{
                break;
            }
        }
        if(k == n)break;
        k = sdivv[k].first;
        double t = sdivv[n - 1].second;
        tc += t;
        for(int i = 0; i < n; i++){
            cars[i][0] += t * cars[i][1];
        }
        cars[k][1] = min(cars[k][1], cars[k + 1][1]);
        cars[k + 1][1] = cars[k][1];
        res[k] = tc;
    }
    return res;
}

int main(){
    vector<vector<int>> cars{{1,2},{2,1},{4,3},{7,2}};
    printVector(wronggetCollisionTimes(cars));
}