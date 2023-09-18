#include <bits/stdc++.h>

using namespace std;

int head = -1;
int idx_to_use = 1;
vector<int> values(100000);
vector<int> next_node(100000);

void Head(int v) {
    values[idx_to_use] = v;
    next_node[idx_to_use] = head;
    head = idx_to_use;
    idx_to_use++;
}
void Insert(int idx, int v) {
    values[idx_to_use] = v;
    next_node[idx_to_use] = next_node[idx];
    next_node[idx] = idx_to_use;
    idx_to_use++;
}
void Delete(int idx) {
    if (idx == 0) {
        head = next_node[head];
    } else {
        next_node[idx] = next_node[next_node[idx]];
    }
}

int main() {
    int n;
    cin >> n;
    char op;
    int idx, v;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op) {
            case 'H':
                cin >> v;
                Head(v);
                break;
            case 'I':
                cin >> idx >> v;
                Insert(idx, v);
                break;
            case 'D':
                cin >> idx;
                Delete(idx);
                break;
            default:
                break;
        }
    }
    int cur_idx = head;
    while (cur_idx != -1) {
        cout << values[cur_idx] << " ";
        cur_idx = next_node[cur_idx];
    }
    cout << endl;
}
