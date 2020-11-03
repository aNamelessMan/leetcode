#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了89.34% 的用户
//根据四平方和定理，任意正整数可表示为四个整数的平方
//最少是四个数的平方和  <==>    n % 8 == 7
//因此只剩下1、2、3三种情况
//尝试拆分成两个数平方和，若不成功则返回3
//a == 0 => !a == 1 =>  !!a == 0
//a != 0 => !a == 0 =>  !!a == 1
int numSquares(int n) {
    while(n % 4 == 0)n /= 4;
    if(n % 8 == 7)return 4;
    for(int a = 0; a * a <= n; a++){
        int b = sqrt(n - a * a);
        if(a * a + b * b == n)
            return !!a + !!b;
    }
    return 3;
}

//暴力dfs显然会超时...
int res = INT_MAX;
void dfs(int n, int t, vector<int> &candidate){//t是已经加上的个数，n是还需补上的数
    if(!n){
        if(t < res)res = t;
        return;
    }else{
        for(auto &i:candidate){
            if(i > n)return;
            dfs(n - i, ++t, candidate);
        }
    }
}
int BFnumSquares(int n) {
    vector<int> candidate;
    int i = 1;
    int squ = i * i;
    while(squ <= n){
        candidate.push_back(squ);
        i++;
        squ = i * i;
    }
    dfs(n, 0, candidate);
    return res;
}

int main(){
    cout << 1 << endl;
}