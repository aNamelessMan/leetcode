#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int size) {
        parent_.resize(size + 1, -1);
        // 初始化，每个节点都是一个集合
        for (int i = 0; i <= size; i++) {
            parent_[i] = i;
        }
        size_.resize(size + 1, 1);
    }
    // 将元素a和b所在集合合并
    void Merge(int idx_a, int idx_b) {
        if (find(idx_a) != find(idx_b)) {  // 不在同一集合
            size_[find(idx_b)] += size_[find(idx_a)];
        }
        parent_[find(idx_a)] = find(idx_b);
    }
    bool Query(int idx_a, int idx_b) { return find(idx_a) == find(idx_b); }
    int Count(int idx) { return size_[find(idx)]; }

private:
    // 返回根节点，并进行路径压缩
    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] =
                find(parent_[x]);  // 注意这里不要写成find(x)，否则会无限递归
        }
        return parent_[x];
    }
    vector<int> parent_;
    vector<int> size_;
};

int main() {
    int n, m;
    cin >> n >> m;
    string op;
    int a, b;
    UnionFind union_find(n);
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "M" || op == "C") {
            cin >> a >> b;
            union_find.Merge(a, b);
        } else if (op == "Q" || op == "Q1") {
            cin >> a >> b;
            if (union_find.Query(a, b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cin >> a;
            cout << union_find.Count(a) << endl;
        }
    }
}
