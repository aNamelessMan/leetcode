#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.25% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了26.33% 的用户
bool bs(int lb, int hb, int target, vector<int> &t){
    if(lb > hb)return false;
    int mid = (lb + hb) / 2;
    if(t[mid] == target)return true;
    else if(t[mid] < target)return bs(mid + 1, hb, target, t);
    else    return bs(lb, mid - 1, target, t);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> t;
    int m = matrix.size();
    if(m == 0)return false;
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            t.push_back(matrix[i][j]);
        }
    }

    return bs(0, m * n - 1, target, t);
}

int main(){
    cout << 1 << endl;
}