#include <bits/stdc++.h>
using namespace std;

// 执行用时：36 ms, 在所有 C++ 提交中击败了45.60% 的用户
// 内存消耗：24.7 MB, 在所有 C++ 提交中击败了33.03% 的用户
vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    if(n == 0)return {};
    if(n == 1)return {a[0]};
    vector<int> v1(n), v2(n), res(n);
    v1[0] = a[0];
    for(int i = 1; i < n; i++){
        v1[i] = v1[i - 1] * a[i];
    }
    v2[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        v2[i] = v2[i + 1] * a[i];
    }
    res[0] = v2[1];
    res[n - 1] = v1[n - 2];
    for(int i = 1; i < n - 1; i++){
        res[i] = v1[i - 1] * v2[i + 1];
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}