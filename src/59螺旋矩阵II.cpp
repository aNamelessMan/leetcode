#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了15.80% 的用户
int fill(int i, int n, int s, vector<vector<int>> &res){
    /*i是起点   n是边长 s是起点的值*/
    int k = i, j = i;
    for(; j <= n - k - 1; j++){
        res[i][j] = s;
        s++;
    }
    s--;
    for(j = n - k - 1; i <= n - k - 1; i++){
        res[i][j] = s;
        s++;
    }
    s--;
    for(i = n - k - 1; j >= k; j--){
        res[i][j] = s;
        s++;
    }
    s--;
    for(j = k; i >= k + 1; i--){
        res[i][j] = s;
        s++;
    }
    return s;//返回s作为下次调用的起点
}

vector<vector<int>> generateMatrix(int n) {
    if(n == 0)return {{}};
    if(n == 1)return {{1}};
    vector<vector<int>> res(n, vector<int>(n));
    int i = 0, s = 1;
    while(i <= (n - 1) / 2){
        s = fill(i, n, s, res);
        i++;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}