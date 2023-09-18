#include <bits/stdc++.h>

using namespace std;
// 先进后出
struct stk {
    stk() { v = vector<int>(1e5); }
    vector<int> v;
    int t = -1;
    void push(int x) {
        t++;
        v[t] = x;
    }
    void pop() { t--; }
    void empty() {
        if (t == -1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    void query() { cout << v[t] << endl; }
};

int main() {
    int m;
    cin >> m;
    string op;
    int v;
    stk stk1;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "push") {
            cin >> v;
            stk1.push(v);
        } else if (op == "pop") {
            stk1.pop();
        } else if (op == "empty") {
            stk1.empty();
        } else if (op == "query") {
            stk1.query();
        }
    }
}
