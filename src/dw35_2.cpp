#include <bits/stdc++.h>
using namespace std;

//5505. 所有排列中的最大和
// 有一个整数数组 nums ，和一个查询数组 requests ，其中 requests[i] = [starti, endi] 。第 i 个查询求 nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi] 的结果 ，
//starti 和 endi 数组索引都是 从 0 开始 的。

// 你可以任意排列 nums 中的数字，请你返回所有查询结果之和的最大值。

// 由于答案可能会很大，请你将它对 10^9 + 7 取余 后返回。

 

// 示例 1：

// 输入：nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
// 输出：19
// 解释：一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
// requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
// requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
// 总和为：8 + 3 = 11。
// 一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
// requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
// requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
// 总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。

// 示例 2：

// 输入：nums = [1,2,3,4,5,6], requests = [[0,1]]
// 输出：11
// 解释：一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。

// 示例 3：

// 输入：nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
// 输出：47
// 解释：一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。

 

// 提示：

//     n == nums.length
//     1 <= n <= 10^5
//     0 <= nums[i] <= 10^5
//     1 <= requests.length <= 10^5
//     requests[i].length == 2
//     0 <= starti <= endi < n

//过了69/82不知道哪里错了....
//...审题不清没看到最后的"对 10^9 + 7 取余 后返回"，一定要审题
//改完后过了78 / 82，然后超时 
int TLEmaxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    long res = 0;

    int freq[nums.size()];
    for(unsigned i = 0; i < nums.size(); i++){
        freq[i] = 0;
    }
    //超时的原因应该在这两层循环
    for(auto &p:requests){
        for(int i = p[0]; i <= p[1]; i++){
            freq[i]++;
        }
    }

    sort(freq, freq + nums.size(), greater<int>());
    sort(nums.begin(), nums.end(), greater<int>());

    for(unsigned i = 0; i < nums.size(); i++){
        res += freq[i] * nums[i];
    }

    return res;
}
// 执行用时：808 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：93.9 MB, 在所有 C++ 提交中击败了100.00% 的用户
int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    long res = 0;
    //因为需要更新尾部后一位，所以需要+1
    int freq[nums.size() + 1];

    for(unsigned i = 0; i < nums.size(); i++){
        freq[i] = 0;
    }

    for(auto &p:requests){
        freq[p[0]]++;
        freq[p[1] + 1]--;
    }

    for(unsigned i = 1; i < nums.size(); i++){
        freq[i] += freq[i - 1];
    }

    sort(freq, freq + nums.size(), greater<int>());
    sort(nums.begin(), nums.end(), greater<int>());

    for(unsigned i = 0; i < nums.size(); i++){
        res += freq[i] * nums[i];
    }

    return res %(1000000000 + 7);
}

int main(){
    vector<int> nums{1,8,5,5,2};
    vector<vector<int>> requests{{4,4},{3,4},{4,4},{2,4},{0,0}};
    cout << maxSumRangeQuery(nums, requests) << endl;
}