#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int &res, vector<int>& toppingCosts, int target, int i, int n){
    if(i == n){
        if(abs(s - target) == abs(res - target)){
            res = min(res, s);
        }else{
            res = abs(s - target) > abs(res - target)?res:s;
        }
        return;
    }
    dfs(s, res, toppingCosts, target, i + 1, n);
    dfs(s + toppingCosts[i], res, toppingCosts, target, i + 1, n);
    dfs(s + 2 * toppingCosts[i], res, toppingCosts, target, i + 1, n);
}
    
int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    int bn = baseCosts.size(), tn = toppingCosts.size();
    int res = INT_MAX;
    for(int i = 0; i < bn; i++){
        int s = baseCosts[i];
        dfs(s, res, toppingCosts, target, 0, tn);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}