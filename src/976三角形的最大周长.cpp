#include<bits/stdc++.h>
using namespace std;

// 执行用时：108 ms, 在所有 C++ 提交中击败了73.32% 的用户
// 内存消耗：20.6 MB, 在所有 C++ 提交中击败了29.01% 的用户
int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());
    int n = A.size(), i;
    for(i = 0; i < n - 2; i++){
        if(A[i] < A[i + 1] + A[i + 2])break;
    }
    if(i == n - 2)return 0;
    return A[i] + A[i + 1] + A[i + 2];
}

int main(){
    cout << 1 << endl;
}