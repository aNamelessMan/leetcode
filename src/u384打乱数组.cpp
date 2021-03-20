#include<bits/stdc++.h>
using namespace std;

// 执行用时：128 ms, 在所有 C++ 提交中击败了73.96% 的用户
// 内存消耗：88.1 MB, 在所有 C++ 提交中击败了68.49% 的用户
class Solution {
private:
    vector<int> pre;
public:
    Solution(vector<int>& nums):pre(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return pre;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = pre;
        for(int i = 0; i < (int)res.size(); i++){
            int j = rand() % (i + 1);
            std::swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int main(){
    cout << "print something." << endl;
}