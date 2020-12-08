#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了16.82% 的用户
vector<int> getRow(int rowIndex) {
    vector<vector<int>> res;
    for(int i = 0; i < rowIndex + 1; i++){
        vector<int> t(i + 1);
        int n = t.size();
        t[0] = 1;
        for(int j = 1; j < n - 1; j++){
            t[j] = res[i - 1][j] + res[i - 1][j - 1];
        }
        t[n - 1] = 1;
        res.push_back(t);
    }
    return res[rowIndex];
}

int main(){
    cout << 1 << endl;
}