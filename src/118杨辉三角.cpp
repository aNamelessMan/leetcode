#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了59.43% 的用户
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for(int i = 0; i < numRows; i++){
        vector<int> t(i + 1);
        int n = t.size();
        t[0] = 1;
        for(int j = 1; j < n - 1; j++){
            t[j] = res[i - 1][j] + res[i - 1][j - 1];
        }
        t[n - 1] = 1;
        res.push_back(t);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}