#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        // for(int i = 0;i < nums.size();++i){//暴力搜索O(n^2)  14.12%
        //     for(int j = i+1;j < nums.size();++j){
        //         if(nums[i] + nums[j] == target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }

        //两遍哈希
        multimap<int, int> idx;//如果哈希查找为O(1)，那么时间复杂度O(n) 50.94%
        for(int i = 0; i != nums.size(); ++i){
            idx.insert({target - nums[i], i});
        }
        for(int i = 0; i != nums.size(); ++i){
            auto tmp = idx.find(nums[i]);
            if(tmp != idx.end()){
                if(nums[i] != target - nums[i]){
                    res.push_back(i);
                    res.push_back(tmp->second);
                    return res;
                }else if(idx.count(nums[i]) > 1){
                    res.push_back(i);
                    tmp++;
                    res.push_back(tmp->second);
                    return res;
                }
            }
        }

        //一遍哈希可以更快，一边插入一边查找对应元素
        return res;
    }
};