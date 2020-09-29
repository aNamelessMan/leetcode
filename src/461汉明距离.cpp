#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了25.51% 的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了6.07% 的用户
//暴力解法
int BFhammingDistance(int x, int y) {
    int res = 0;
    for(int i = 30; i >= 0; i--){
        int n = pow(2, i);
        bool same = true;
        if(x >= n){same = !same;x -= n;}
        if(y >= n){same = !same;y -= n;}
        if(!same)res++;
    }
    return res;
}
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了67.20% 的用户
int hammingDistance(int x, int y) {//先异或，再求1的个数
    int res = 0;
    int r = x ^ y;
    while(r){
        if(r % 2)res++;
        r /= 2;
    }
    return res;
}
int main(){
    cout << hammingDistance(1, pow(2, 31) - 1) << endl;
}