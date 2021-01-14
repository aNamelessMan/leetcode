#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了99.77% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了98.63% 的用户
//记得每次将前一次的数对5取余，不影响正确性，防止溢出
vector<bool> prefixesDivBy5(vector<int>& A) {
    int pre = 0, n = A.size();
    vector<bool> res;
    for(int i = 0; i < n; i++){
        pre %= 5;
        pre = 2 * pre + A[i];
        if(pre % 5)res.push_back(false);
        else res.push_back(true);
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}