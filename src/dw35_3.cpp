#include<bits/stdc++.h>
using namespace std;
//1590.使数组和能被 P 整除  
int subArraySum(int i, int j, long p[]){
    if(i == 0)return *(p+j);
    else    return (*(p+j)) - (*(p + i - 1));
}
//TLE
int BFminSubarray(vector<int>& nums, int p) {
    unsigned long res = -1;
    long presum[nums.size()];
    presum[0] = nums[0];
    for(unsigned i = 1; i < nums.size(); i++){
        presum[i] = presum[i - 1] + nums[i];
    }
    //特殊情况
    if(presum[nums.size() - 1] % p == 0)return 0;

    for(unsigned i = 0; i < nums.size(); i++){
        for(unsigned j = i; j < nums.size(); j++){
            //注意%的优先级大于-
            if( (presum[nums.size() - 1] - subArraySum(i, j, presum )) % p == 0 && (j - i + 1) < res){
                res = (j - i + 1);
            }
        }
    }

    if(res == nums.size())return -1;
    return res;
}
// 执行用时：420 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：69.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
int minSubarray(vector<int>& nums, int p) {
    //先求数组总和取余所得值    mod
    long long sum = 0;
    for(int e:nums)sum += e;
    long mod = sum % p;

    if(mod == 0)return 0;

    int res = nums.size();
    //用来存 前缀和取余 与 对应下标
    unordered_map<long, int> table;
    table[0] = -1;
    sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        long curmod = sum % p;
        table[curmod] = i;//更新或者添加pair{curmod, i}，可以确保 余值对应的下标是当前遍历到最大的，也就是最近的
        //target = 1.cur > mod      cur - mod
        //         2.cur < mod      curmod - mod + p
        long targetmod = curmod >= mod ? (curmod - mod) : (curmod - mod + p);
        //如果有targetmod，取它的下标与res中更小的值来更新res
        if(table.count(targetmod))
            res = min(res, (i - table[targetmod]));
    }
    return res == nums.size() ? -1 : res;
}

int main(){
    vector<int> nums{1000000000,1000000000,1000000000};
    int p = 3;
    cout << minSubarray(nums, p) << endl;
}