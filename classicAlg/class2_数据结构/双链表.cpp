#include <bits/stdc++.h>

using namespace std;

/*
input:
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2

output:
8 7 7 3 2 9
*/

vector<int> prev_idxs(1e5 + 10);
vector<int> next_idxs(1e5 + 10);
vector<int> values(1e5 + 10);
int idx_to_set = 2;

// 0和1分别是首尾虚节点
void Init() {
    prev_idxs[0] = -1;
    next_idxs[0] = 1;

    prev_idxs[1] = 0;
    next_idxs[1] = -1;
}

/*
!不要在接口内部补偿k的偏移，要在接口外部（即main中）做
不然就是假设k是未补偿索引，
那么在复用 其他函数时，入参k不能直接用prev_idxs/next_idxs里的值
还得反补偿回去，很蛋疼
*/

void InsertToRight(int k, int v) {
    values[idx_to_set] = v;
    prev_idxs[idx_to_set] = k;
    next_idxs[idx_to_set] = next_idxs[k];

    prev_idxs[next_idxs[k]] = idx_to_set;
    next_idxs[k] = idx_to_set;

    idx_to_set++;
}

void InsertToLeft(int k, int v) { InsertToRight(prev_idxs[k], v); }

void Left(int v) { InsertToRight(0, v); }

void Right(int v) { InsertToLeft(1, v); }

void Delete(int k) {
    prev_idxs[next_idxs[k]] = prev_idxs[k];
    next_idxs[prev_idxs[k]] = next_idxs[k];
}

int main() {
    int m;
    cin >> m;
    string op;
    int idx, v;
    Init();
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "L") {
            cin >> v;
            Left(v);
        } else if (op == "R") {
            cin >> v;
            Right(v);
        } else if (op == "IL") {
            cin >> idx >> v;
            InsertToLeft(idx + 1, v);
        } else if (op == "IR") {
            cin >> idx >> v;
            InsertToRight(idx + 1, v);
        } else if (op == "D") {
            cin >> idx;
            Delete(idx + 1);
        } else {
        }
    }
    int cur_idx = next_idxs[0];
    while (cur_idx != 1) {
        cout << values[cur_idx] << " ";
        cur_idx = next_idxs[cur_idx];
    }
    cout << endl;
}
