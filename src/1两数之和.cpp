#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.97% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了96.09% 的用户
//2021.1.24二刷 一遍哈希，边读取插入边查找
vector<int> secondtwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;//num-index对
    for(int i = 0, n = nums.size(); i < n; i++){
        auto iter = m.find(target - nums[i]);
        if(iter != m.end())return {iter->second, i};
        m[nums[i]] = i;
    }
    return {-1, -1};
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.34% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了24.34% 的用户
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

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

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.97% 的用户
// 内存消耗：8.6 MB, 在所有 C++ 提交中击败了97.94% 的用户
//暴力解法  这题的测试用例应该有变动，之前暴力解法很慢
vector<int> BFtwoSum(vector<int>& nums, int target) {
    vector<int> res;
    for(int i = 0;i < nums.size();++i){//暴力搜索O(n^2)  14.12%
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

int main(){
    cout << "print something." << endl;
}