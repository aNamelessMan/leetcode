#include<bits/stdc++.h>
using namespace std;

/**
 * 执行用时：396 ms, 在所有 C++ 提交中击败了100.00% 的用户
 * 内存消耗：52 MB, 在所有 C++ 提交中击败了100.00% 的用户
 * 思路见https://leetcode-cn.com/problems/closest-subsequence-sum/solution/zhuang-ya-dp-zhi-cong-kan-shu-ju-fan-wei-kve3/
 * 简单来说就是把数据两等分再各自枚举两部分的子数组和
 * 整个数组的子数组和要么是前面枚举中的一个，要么是两个部分分别去一个子数组和的和
 * 枚举半个数组 复杂度为    O(n/2 * 2(n/2))
 * 两部分和的情况排序和使用双指针来求
 * 复杂度分析
 * 本解法的时间复杂度为 O(n⋅2n/2)O(n\cdot2^{n/2})O(n⋅2n/2)。
 * 求解 lsum,rsum\textit{lsum}, \textit{rsum}lsum,rsum 的过程分别需要 O((n/2)⋅2n/2)=O(n⋅2n/2)O((n/2) \cdot 2^{n/2}) = O(n\cdot2^{n/2})O((n/2)⋅2n/2)=O(n⋅2n/2) 的时间；
 * 排序过程需要 O((2n/2)log⁡(2n/2))=O(n⋅2n/2)O((2^{n/2})\log(2^{n/2})) = O(n\cdot2^{n/2})O((2n/2)log(2n/2))=O(n⋅2n/2) 的时间；
 * 最后的双指针部分需 O(2n/2)O(2^{n/2})O(2n/2) 的时间。
 * 详见上面的连接，说的很精彩
*/
int minAbsDifference(vector<int>& nums, int goal) {
    int n = nums.size(), mid = n / 2;
    vector<int> l = {0}, r = {0};
    for(int i = 0; i < mid; i++){
        int m = l.size();
        for(int j = 0; j < m; j++){
            l.push_back(nums[i] + l[j]);
        }
    }
    for(int i = mid; i < n; i++){
        int m = r.size();
        for(int j = 0; j < m; j++){
            r.push_back(nums[i] + r[j]);
        }
    }
    int res = abs(goal);
    for(int i:l){
        res = min(res, abs(i - goal));
    }
    for(int i:r){
        res = min(res, abs(i - goal));
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int lp = 0, rp = r.size() - 1;
    while(lp < (int)l.size() && rp >= 0){
        int cur = l[lp] + r[rp];
        res = min(res, abs(goal - cur));
        if(cur > goal){
            rp--;
        }else{
            lp++;
        }
    }
    return res;
}

/*WA    贪心算法会出错
[1556913,-259675,-7667451,-4380629,-4643857,-1436369,7695949,-4357992,-842512,-118463]
-9681425
*/
static bool cmp(const int &i1, const int &i2){
    return abs(i1) < abs(i2);
}
    
int greedyminAbsDifference(vector<int>& nums, int goal) {
    int res = abs(goal);
    int cur = 0, n = nums.size();
    
    
    for(int i = 0; i < n; i++){
        nums[i] -= goal;
    }
    auto iter = min_element(nums.begin(), nums.end(), cmp);
    cur = *iter;
    res = min(res, abs(cur));
    nums.erase(iter);
    
    for(int i = 0; i < n - 1; i++){
        for(int i = 0; i < (int)nums.size(); i++){
            nums[i] += goal;
        }
        goal = -cur;
        for(int i = 0; i < (int)nums.size(); i++){
            nums[i] -= goal;
        }
        iter = min_element(nums.begin(), nums.end(), cmp);
        cur = *iter;//当前差值就是这一步所选值和这一步goal的差值
        res = min(res, abs(cur));
        nums.erase(iter);
    }
    return res;
}

//60 / 69 个通过测试用例    TLE
//复杂度n * 2^n n = 40  2^40 = 1e12
int BFminAbsDifference(vector<int>& nums, int goal) {
    int res = abs(goal);
    vector<int> v = {0};
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int m = v.size();
        for(int j = 0; j < m; j++){
            int nw = v[j] + nums[i];
            if(nw == goal)return 0;
            res = min(res, abs(goal - nw));
            v.push_back(nw);
        }
    }
    return res;
}

int main(){
    vector<int> nums = {5, -7, 3, 5};
    cout << minAbsDifference(nums, 6) << endl;
    nums = {-5862,-3226,-5358,7874,-8960,356,8119,-3269,-4163,-205};
    cout << minAbsDifference(nums, -40729811) << endl;
    nums = {7, -9, 15, -2};
    cout << minAbsDifference(nums, -5) << endl;
    cout << "print something." << endl;
}