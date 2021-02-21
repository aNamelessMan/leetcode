#include <bits/stdc++.h>
using namespace std;

/*
dfs一般解决 
    组合问题
    连通性/可达性问题
因此这题是典型的dfs
*/
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了84.98% 的用户
//2021.2.21二刷
void dfs(vector<string> &res, string &digits, int i, int n, unordered_map<int, vector<char>> &m, string &tmp){
    if(i == n){
        res.push_back(tmp);
        return;
    }
    int c = digits[i] - '0';
    for(auto &ch:m[c]){
        tmp += ch;
        dfs(res, digits, i + 1, n, m, tmp);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    int n = digits.size();
    vector<string> res;
    if(n == 0)return res;
    unordered_map<int, vector<char>> m;
    m[2] = {'a', 'b', 'c'};
    m[3] = {'d', 'e', 'f'};
    m[4] = {'g', 'h', 'i'};
    m[5] = {'j', 'k', 'l'};
    m[6] = {'m', 'n', 'o'};
    m[7] = {'p', 'q', 'r', 's'};
    m[8] = {'t', 'u', 'v'};
    m[9] = {'w', 'x', 'y', 'z'};
    string tmp;
    dfs(res, digits, 0, n, m, tmp);
    return res;
} 

int main(){
    cout << "print sth." << endl;
}