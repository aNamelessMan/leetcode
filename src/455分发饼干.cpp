#include<bits/stdc++.h>
using namespace std;

// 执行用时：88 ms, 在所有 C++ 提交中击败了59.17% 的用户
// 内存消耗：17.5 MB, 在所有 C++ 提交中击败了10.38% 的用户
//一道简单题错了好几次，吐了
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, n = s.size(), m = min((int)g.size(), n);
    if(m == 0 || n == 0)return 0;
    auto iter = lower_bound(s.begin(), s.end(), g[0]);
    if(iter == s.end())return 0;
    i++;
    for( ; i < m; i++){
        iter = lower_bound(iter + 1, s.end(), g[i]);
        if(iter == s.end())break;
    }
    return i;
}

int main(){
    cout << 1 << endl;
}