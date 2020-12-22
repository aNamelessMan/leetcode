#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了5.36% 的用户
uint32_t reverseBits(uint32_t n) {
    queue<int> q;
    int c = 2;
    while(n){
        q.push(n % c);
        n /= c;
    }
    while(q.size() < 32){//注意补齐32位
        q.push(0);
    }
    uint32_t res = 0;
    while(!q.empty()){
        res = res * 2 + q.front();
        q.pop();
    }
    return res;
}

int main(){
    cout << reverseBits(43261596) << endl;
}