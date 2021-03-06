#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了75.31% 的用户
void dfs(int &res, int i, int n, string &str){
    if(i == n){
        res++;
        return;
    }
    dfs(res, i + 1, n, str);
    if(str[i] == '1' && i < n - 1){
        dfs(res, i + 2, n, str);
    }
    if(str[i] == '2' && i < n - 1 && str[i + 1] <= '5'){
        dfs(res, i + 2, n, str);
    }
}

int translateNum(int num) {
    string str = to_string(num);
    int n = str.size(), res = 0;
    dfs(res, 0, n, str);
    return res;
}

int main(){
    cout << "print sth." << endl;
}