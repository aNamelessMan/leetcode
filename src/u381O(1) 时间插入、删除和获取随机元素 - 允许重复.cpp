#include<bits/stdc++.h>
using namespace std;

// 执行用时：84 ms, 在所有 C++ 提交中击败了85.29% 的用户
// 内存消耗：26.9 MB, 在所有 C++ 提交中击败了5.10% 的用户
class RandomizedCollection {
public:
    RandomizedCollection() {}
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;
    }
    bool remove(int val) {
        if (m[val].empty()) return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if (nums.size() - 1 != idx) {
            int t = nums.back();
            nums[idx] = t;
            m[t].erase(nums.size() - 1);
            m[t].insert(idx);
        } 
        nums.pop_back();
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
};

int main(){
    cout << 1 << endl;
}