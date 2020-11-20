#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了15.79% 的用户
void tras(vector<int> &res, vector<vector<int>>& matrix, int i, int m, int n){
/*起点是[i, i]  ->  终点是[i, n - i - 1]
        [i + 1, n - i - 1]  [m - i - 1, n - i - 1]
        [m - i - 1, n - i - 2]  [m - i - 1, i]
        [m - i - 2, i]  [i + 1, i]
*/
    int j = i, k = i;
    for(; j <= n - k - 1; j++){
        res.push_back(matrix[i][j]);
    }
    j--;
    i++;
    if(i > m - k - 1)return;
    for(; i <= m - k - 1; i++){
        res.push_back(matrix[i][j]);
    }
    i--;
    j--;
    if(j < k)return;
    for(; j >= k; j--){
        res.push_back(matrix[i][j]);
    }
    j++;
    i--;
    if(i < k + 1)return;
    for(; i >= k + 1; i--){
        res.push_back(matrix[i][j]);
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int i = 0, m = matrix.size();
    if(!m)return {};
    int n = matrix[0].size();
    int ms = m, ns = n;
    vector<int> res;
    while(m > 0 && n > 0){
        tras(res, matrix, i, ms, ns);
        m -= 2;
        n -= 2;
        i++;
    }
    return res;
}

int main(){
    vector<vector<int>> m{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> m1{{9, 5, 6}};
    vector<int> res = spiralOrder(m);
    vector<int> res1 = spiralOrder(m1);
    cout << 1 << endl;
}