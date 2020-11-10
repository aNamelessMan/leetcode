#include<bits/stdc++.h>
using namespace std;

long long playGames(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size(), max = A[n - 1], t = max;
    for(int i = 0; i < n; i++)A[i] -= max;
    for(int i = 0; i < n; i++)max += A[i];
    if(max <= 0)return t;
    return ceil((double)max / (n - 1)) + t;
}

int main(){
    vector<int> A({2, 2, 2, 2});
    cout << playGames(A) << endl;
}