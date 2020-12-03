#include<bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了83.04% 的用户
// 内存消耗：22.8 MB, 在所有 C++ 提交中击败了5.85% 的用户
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val))return false;
        else{
            nums.push_back(val);
            m[val] = nums.size() - 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val))return false;
        else{
            int t = nums.back();
            nums[m[val]] = t;
            m[t] = m[val];

            nums.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int>m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    cout << 1 << endl;
}