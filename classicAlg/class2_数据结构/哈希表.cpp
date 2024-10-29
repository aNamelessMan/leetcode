#include <bits/stdc++.h>

using namespace std;

// hash 将对象映射到一个较小的固定的区间
class HashMap {
public:
  explicit HashMap(int count, int empty_val) {
    count_ = 3 * count; // 一般取比个数大的最大素数的三倍，懒得写了
    empty_val_ = empty_val;
    data.resize(count_, empty_val_);
  }
  void Insert(int num) { data[Find(num)] = num; }
  bool Query(int num) { return data[Find(num)] == num; }

private:
  int HashFunc(int num) { return ((num % count_) + count_) % count_; }
  // 开放定址法，比较简单，只用一个data数组即可
  // 拉链法得用两个数组模拟链表
  // 如果要支持删除，算法题里一般做逻辑删除，用bool值标记即可，不会实际删除

  // 返回 num 的下标 或应当存的下标（对于不存在的情况）
  int Find(int num) {
    int pos = HashFunc(num);
    while (data[pos] != num && data[pos] != empty_val_) {
      pos++;
      if (pos == count_) {
        pos = 0;
      }
    }
    return pos;
  }
  int count_;
  int empty_val_;
  vector<int> data;
};

int main() {
  int n, t;
  cin >> n;
  HashMap hash_map(n, 1e9 + 10);
  char op;
  for (int i = 0; i < n; i++) {
    cin >> op >> t;
    switch (op) {
    case 'I': {
      hash_map.Insert(t);
      break;
    }
    case 'Q': {
      if (hash_map.Query(t)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
      break;
    }
    }
  }
}