#include<bits/stdc++.h>
using namespace std;

// 执行用时：44 ms, 在所有 C++ 提交中击败了78.34% 的用户
// 内存消耗：20.7 MB, 在所有 C++ 提交中击败了25.99% 的用户
vector<int> sortArrayByParityII(vector<int>& A) {
    int n = A.size();
    vector<int> wrongidx;
    for(int i = 0; i < n; i += 2){
        if(A[i] % 2)wrongidx.push_back(i);
    }
    if(!wrongidx.size())return A;
    int j = 0;
    for(int i = 1; i < n; i += 2){
        if(!(A[i] % 2)){
            swap(A[i], A[wrongidx[j++]]);
        }
    }
    return A;
}

int main(){
    cout << 1 << endl;
}