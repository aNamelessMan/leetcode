#include<bits/stdc++.h>
using namespace std;

//感觉比第一题还简单
double averageWaitingTime(vector<vector<int>>& customers) {
    double res = 0, n = customers.size();
    
    int cura = customers[0][0], curf = customers[0][0] + customers[0][1];
    res += (curf - cura);
    for(int i = 1; i < n; i++){
        cura = customers[i][0];
        curf = max(cura, curf) + customers[i][1];
        res += (curf - cura);
    }
    
    return res / n;
}

int main(){
    vector<vector<int>> cus = {{1,2},{2,5},{4,3}};
    cout << averageWaitingTime(cus) << endl;

    cus = {{1,2},{2,5},{4,3}};
    cout << averageWaitingTime(cus) << endl;

    cus = {{5,2},{5,4},{10,3},{20,1}};
    cout << averageWaitingTime(cus) << endl;
}