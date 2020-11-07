#include<bits/stdc++.h>
using namespace std;

// 执行用时：84 ms, 在所有 C++ 提交中击败了41.25% 的用户
// 内存消耗：14.8 MB, 在所有 C++ 提交中击败了33.11% 的用户
/*
在累积和数组sums[n]中找出符合
1.i >= j
2.lower <= sums[i] - sums[j] <= upper
的i-j对的个数

即sums[i] - lower => sums[j] => sums[i] - upper
对每一个i找出满足条件j的个数，累加即可
*/
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    int res = 0;
    long sum = 0;
    multiset<long> sums;
    sums.insert(0);
    for(int i = 0; i < n; i++){
        sum += nums[i];//sum相当于上面所说的sums[i]
        res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
        sums.insert(sum);
    }
    return res;
}

//暴力解法  O(n^2)  TLE 61 / 61 个通过测试用例
int BFcountRangeSum(vector<int>& nums, int lower, int upper) {
    if(nums.empty())return 0;
    int n = nums.size();
    int res = 0;

    for(int i = 0; i < n; i++){
        long p = 0;
        for(int j = i; j < n; j++){
            p += nums[j];
            if(p >= lower && p <= upper)res++;
        }
    }

    return res;
}

int main(){
    cout << 1 << endl;
}