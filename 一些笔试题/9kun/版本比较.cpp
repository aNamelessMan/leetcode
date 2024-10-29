#include <bits/stdc++.h>

using namespace std;
/*
版本比较，给定两个字符串，由数字和.组成，如果字符串1大于字符串2则大印1，小于大印-1，等于，打印0

1.00
1.000
0

1.00.01
1.00
1
*/

vector<string> split(const string &str) {
  vector<string> res;
  int sz = str.size();
  string t;
  for (int i = 0; i < sz; i++) {
    if (str[i] == '.') {
      if (t.empty()) {
        t = "0";
      }
      res.push_back(t);
      t.clear();
    }
    t += str[i];
  }

  if (t.empty()) {
    t = "0";
  }
  res.push_back(t);

  return res;
}

void process(const vector<vector<string>> &input) {
  for (const auto &p : input) {
    vector<string> numbers1 = split(p[0]);
    vector<string> numbers2 = split(p[1]);
    int sz1 = numbers1.size();
    int sz2 = numbers2.size();
    bool done = false;
    for (int i = 0; i < sz1 || i < sz2; i++) {
      int n1 = 0;
      int n2 = 0;
      if (i < sz1) {
        n1 = atoi(numbers1[0].c_str());
      }
      if (i < sz2) {
        n2 = atoi(numbers2[0].c_str());
      }
      if (n1 != n2) {
        cout << (n1 > n2 ? 1 : -1) << endl;
        return;
      }
    }
    cout << 0 << endl;
  }
}

int main() {
  vector<vector<string>> input;
  input.push_back({"1.00", "1.000"});
  input.push_back({"1.00.01", "1.00"});
  process(input);
}
