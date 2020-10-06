#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了69.58% 的用户
// 内存消耗：8.3 MB, 在所有 C++ 提交中击败了24.64% 的用户
//找规律的题
//可以发现如果是奇数，那么是他除以2后1的个数加1
//如果是偶数，就是除以2后1的个数
vector<int> countBits(int num) {
    if(!num)return {0};

    vector<int> res;
    res.push_back(0);
    res.push_back(1);
    for(int i = 2; i <= num; i++){
        if(i % 2)res.push_back(res[i / 2] + 1);
        else res.push_back(res[i / 2]);
    }

    return res;
}

int main(){
    cout << 1 << endl;
}