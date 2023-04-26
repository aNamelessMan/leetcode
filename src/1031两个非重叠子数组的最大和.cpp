//
// Created by 秦俊 on 2023/4/26.
//
#include <vector>

using namespace std;

//We can use prefix sums to calculate any subarray sum quickly. For each L length subarray, find the best possible M length subarray that occurs before and after it.
//看到遍历子数组和，就要想到前缀和数组
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int res = -1;
        for(int i = 0; i + firstLen - 1 < n; i++){
            int sum1;
            if(i != 0){
                sum1 = prefixSum[i + firstLen - 1] - prefixSum[i - 1];
            }else{
                sum1 = prefixSum[i + firstLen - 1];
            }
            for(int j = 0; j + secondLen - 1 < i; j++){
                int sum2;
                if(j != 0){
                    sum2 = prefixSum[j + secondLen - 1] - prefixSum[j - 1];
                }else{
                    sum2 = prefixSum[j + secondLen - 1];
                }
                res = max(res, sum1 + sum2);
            }
            for(int j = i + firstLen; j + secondLen - 1 < n; j++){
                int sum2;
                if(j != 0){
                    sum2 = prefixSum[j + secondLen - 1] - prefixSum[j - 1];
                }else{
                    sum2 = prefixSum[j + secondLen - 1];
                }
                res = max(res, sum1 + sum2);
            }
        }
        return res;
    }
};
