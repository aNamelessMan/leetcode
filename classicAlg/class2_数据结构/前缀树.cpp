#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

/*
input:
5
I abc
Q abc
Q ab
I ab
Q ab

output:
1 0 1
*/
// 自己想的写法
class TrieNode {
public:
    // 两个接口都是假定自己当前节点的字符已经被迭代过了，根据头部找下一个节点
    // 即在当前节点的sub_node_里找target[start]这个字符
    void insert(const string& target, size_t start) {
        // 没有下一节点了，则当前节点计数+1
        if (start == target.size()) {
            count_++;
        } else {
            char head = target.at(start);

            if (sub_node_.find(head) == sub_node_.end()) {
                sub_node_[head] = new TrieNode();
            }
            sub_node_[head]->insert(target, start + 1);
        }
    }
    int query(const string& target, size_t start) {
        // 没有下一节点了，则返回当前节点计数
        if (start == target.size()) {
            return count_;
        }
        char head = target.at(start);
        if (sub_node_.find(head) == sub_node_.end()) {
            return 0;
        }
        return sub_node_[head]->query(target, start + 1);
    }

private:
    int count_ = 0;
    // unordered_map<char, TrieNode*> sub_node_;
    map<char, TrieNode*>
        sub_node_;  // 这样就是名副其实的前缀树了，map的实现就是树
};

int main() {
    int n;
    cin >> n;

    char op;
    string target;
    TrieNode trie;
    for (int i = 0; i < n; i++) {
        cin >> op >> target;
        if (op == 'I') {
            trie.insert(target, 0);
        } else {
            cout << trie.query(target, 0) << endl;
        }
    }
}
