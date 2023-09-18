#include <bits/stdc++.h>

using namespace std;

struct Queue {
    int head;
    int tail;
    vector<int> val;
    Queue() {
        head = 0;
        tail = -1;
        val = vector<int>(1e6);
    }

    void push(int x) {
        tail++;
        val[tail] = x;
    }
    void pop() { head++; }
    void empty() {
        if (tail < head) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    void query() { cout << val[head] << endl; }
};

int main() {
    int m;
    cin >> m;
    string op;
    int v;
    Queue q;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "push") {
            cin >> v;
            q.push(v);
        } else if (op == "pop") {
            q.pop();
        } else if (op == "empty") {
            q.empty();
        } else if (op == "query") {
            q.query();
        }
    }
}
