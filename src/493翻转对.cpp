#include<bits/stdc++.h>
using namespace std;


//基于BIT树状数组的做法
// 执行用时：388 ms, 在所有 C++ 提交中击败了68.44% 的用户
// 内存消耗：45.4 MB, 在所有 C++ 提交中击败了56.88% 的用户
int search(vector<int> &bit, int i){
    int sum = 0;

    while(i < bit.size()){
        sum += bit[i];
        i += i & -i;
    }

    return sum;
}

void insert(vector<int> &bit, int i){
    while(i > 0){
        bit[i] += 1;
        i -= i & -i;
    }
}

int index(vector<int> &arr, long val){
    int l = 0, r = arr.size() - 1, m = 0;

    while (l <= r) {
    	m = l + ((r - l) >> 1);
    		
    	if (arr[m] >= val) {
    	    r = m - 1;
    	} else {
    	    l = m + 1;
    	}
    }
    
    return l + 1;
}

int reversePairs(vector<int> &nums){
    int res = 0;
    vector<int> copy = nums;
    vector<int> bit(copy.size() + 1);

    sort(copy.begin(), copy.end());
    for(auto &ele:nums){
        res += search(bit, index(copy, (long)2 * ele + 1));
        insert(bit, index(copy, ele));
    }

    return res;
}

//35 / 137 个通过测试用例   暴力解法    应该是正确的
int BFreversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)return 0;
    map<long, int> cnt;
    int res = 0;
    for(int i = 0; i < n; i++){
        auto iter = cnt.lower_bound(2 * (long)nums[i]);
        if(iter == cnt.end()){
            cnt[nums[i]]++;
            continue;
        }
        if(iter->first == (long)2 * nums[i])
            iter++;
        while(iter != cnt.end()){
            res += iter->second;
            iter++;
        }
        cnt[nums[i]]++;
    }
    return res;
}

int main(){
    vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    // vector<int> nums = {-5, -5};
    //vector<int> nums = {1, 3, 2, 3, 1};
    cout << BFreversePairs(nums) << endl;
}