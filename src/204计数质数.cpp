#include<bits/stdc++.h>
using namespace std;

// 执行用时：468 ms, 在所有 C++ 提交中击败了21.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了77.14% 的用户
bool isPrime(int n){
    if(n % 2 == 0)return n == 2;
    if(n % 3 == 0)return n == 3;
    if(n % 5 == 0)return n == 5;
    for(int i = 7; i * i <= n; i += 2){
        if(n % i == 0)return false;
    }
    return true;
}

int countPrimes(int n) {
    int res = 0;
    if(n <= 1)return res;
    for(int i = 2; i < n; i++){
        if(isPrime(i))res++;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}