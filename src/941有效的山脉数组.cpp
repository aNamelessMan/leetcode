#include<bits/stdc++.h>
using namespace std;
// 执行用时：56 ms, 在所有 C++ 提交中击败了90.92% 的用户
// 内存消耗：21.2 MB, 在所有 C++ 提交中击败了5.27% 的用户
bool validMountainArray(vector<int>& A) {
    int n = A.size();
    if(n < 3)return false;
    //首尾单独判断
    if(A[1] > A[0]){}
    else    return false;

    int i = 1;
    for(;i < n - 1; i++){
        if(A[i] == A[i - 1])return false;
        else if(A[i] > A[i - 1])continue;
        else    break;
    }

    for(;i < n;i++){
        if(A[i] < A[i - 1])continue;
        else    return false;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}