#include<bits/stdc++.h>
using namespace std;

// 执行用时：344 ms, 在所有 C++ 提交中击败了12.90% 的用户
// 内存消耗：27.2 MB, 在所有 C++ 提交中击败了54.61% 的用户
vector<int> mergeVector(vector<int> nums1, vector<int> nums2){
    vector<int> res;
    while(!nums1.empty() || !nums2.empty()){
        vector<int> &tmp = nums1 > nums2?nums1:nums2;
        res.push_back(tmp[0]);
        tmp.erase(tmp.begin());
    }
    return res;
}

vector<int> maxVector(vector<int>& nums, int k){
    //k是要从nums中取的数的个数，此处与402题一模一样，只是改成递减栈
    int n = nums.size(), drop = n - k;//drop是需要去掉的个数
    vector<int> res;
    for(int c:nums){
        while(drop && res.size() && res.back() < c){
            res.pop_back();
            drop--;
        }
        res.push_back(c);
    }
    res.resize(k);
    return res;
}
//O(k * k * n)
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res;
    for (int i = max(0, k - n2); i <= min(k, n1); ++i) {//i是从nums1中取的数的个数
        res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
    }
    return res;
}

int main(){
    cout << 1 << endl;
}