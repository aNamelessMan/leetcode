/*执行用时 :740 ms, 在所有 C++ 提交中击败了14.12% 的用户
内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0;i < nums.size();++i){
            for(int j = i+1;j < nums.size();++j){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};