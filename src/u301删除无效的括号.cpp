#include<bits/stdc++.h>
using namespace std;

// 执行用时：100 ms, 在所有 C++ 提交中击败了29.15% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了29.01% 的用户
bool isValid(string t) {
    int cnt = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        if (t[i] == '(') ++cnt;
        else if (t[i] == ')' && --cnt < 0) return false;
    }
    return cnt == 0;
}
//bfs
vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    unordered_set<string> visited({s});
    queue<string> q({s});//这里不能写成q{s}会编译错误   
    //因为初始化容器 需要用的是一个列表的的值例如{s, ..., }   上面同理，也许有些容器可以不加小括号，但为了保险起见，以后初始化一律写成({...})的形式
    bool found = false;
    while (!q.empty()) {
        string t = q.front(); q.pop();
        if (isValid(t)) {
            res.push_back(t);
            found = true;
        }
        if (found) continue;
        for (int i = 0; i < (int)t.size(); ++i) {
            if (t[i] != '(' && t[i] != ')') continue;
            string str = t.substr(0, i) + t.substr(i + 1);
            if (!visited.count(str)) {
                q.push(str);
                visited.insert(str);
            }
        }
    }
    return res;
}

int main(){
    cout << "print something." << endl;
    cout << __cplusplus << endl;
}