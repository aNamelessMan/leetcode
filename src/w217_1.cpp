#include<bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int m = accounts.size(), n = accounts[0].size(), res = INT_MIN;
    for(int i = 0; i < m; i++){
        int t = 0;
        for(int j = 0; j < n; j++){
            t += accounts[i][j];
        }
        res = max(res, t);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}