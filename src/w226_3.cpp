#include<bits/stdc++.h>
using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    //第i天能吃到的糖果范围是第i + 1到第(i + 1) * max个
    vector<long> presum;
    for(int i: candiesCount){
        presum.push_back(i);
    }
    int n = presum.size();
    for(int i = 1; i < n; i++){
        presum[i] += presum[i - 1];
    }
    //第j类型的糖果范围是presum[j - 1] + 1到presum[j]
    vector<bool> res;
    int m = queries.size();
    for(int i = 0; i < m; i++){
        long mn, mx;
        if(queries[i][0] == 0){
            mn = 1;
            mx = presum[0];
        }else{
            mn = presum[queries[i][0] - 1] + 1;
            mx = presum[queries[i][0]];
        }
        long mne = queries[i][1] + 1;
        long mxe = (long)(queries[i][1] + 1) * queries[i][2];
        //这两区间有重合则可以吃到
        if((mxe < mn) || (mne > mx)){
            res.push_back(false);
        }else{
            res.push_back(true);
        }
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}