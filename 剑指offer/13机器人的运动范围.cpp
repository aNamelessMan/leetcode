#include <bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了9.95% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了5.03% 的用户
int calc(int i, int j){
    int res = 0;
    while(i){
        res += (i % 10);
        i /= 10;
    }
    while(j){
        res += (j % 10);
        j /= 10;
    }
    return res;
}

void dfs(int i, int j, int m, int n, unordered_set<int> &path, unordered_set<int> &canreach, int k){
    if(i < 0 || i >= m || j < 0 || j >= n || path.count(i * n + j) || calc(i, j) > k || canreach.count(i * n + j))return;
    path.insert(i * n + j);
    dfs(i - 1, j, m, n, path, canreach, k);
    dfs(i + 1, j, m, n, path, canreach, k);
    dfs(i, j - 1, m, n, path, canreach, k);
    dfs(i, j + 1, m, n, path, canreach, k);
    path.erase(i * n + j);
    canreach.insert(i * n + j);

}

int movingCount(int m, int n, int k) {
    unordered_set<int> path;
    unordered_set<int> canreach;
    dfs(0, 0, m, n, path, canreach, k);
    return canreach.size();
}

int main(){
    cout << "print sth." << endl;
}