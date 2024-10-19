#include <bits/stdc++.h>
using namespace std;

// 执行用时分布14ms击败99.65%
// 消耗内存分布23.43MB 击败69.55%
// 先排序，将排序完结果作为key
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> idx;
        for (const auto& str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            idx[copy].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& p : idx) {
            res.push_back(p.second);
        }
        return res;
    }
};

// 执行用时：144 ms, 在所有 C++ 提交中击败了10.23% 的用户
// 内存消耗：27.7 MB, 在所有 C++ 提交中击败了5.01% 的用户
// 异位词 即各字母出现次数相等
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<vector<int>, int> c;
    int idx = 0;
    for (auto& str : strs) {
        vector<int> tmp(26, 0);
        for (auto& c : str) {
            tmp[c - 'a']++;
        }
        if (c.count(tmp))
            res[c[tmp]].push_back(str);
        else {
            c.insert({tmp, idx++});  // 注意c和res都要添加
            res.push_back({str});
        }
    }
    return res;
}

int main() {
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    groupAnagrams(strs);
    cout << 1 << endl;
}