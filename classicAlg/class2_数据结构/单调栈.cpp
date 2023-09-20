#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        cin >> t;
        while (!stk.empty() && stk.top() >= t) {
            stk.pop();
        }
        if (stk.empty()) {
            cout << "-1 ";
        } else {
            cout << stk.top() << " ";
        }
        stk.push(t);
    }
    cout << endl;
}
