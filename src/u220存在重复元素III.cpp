#include<bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了58.30% 的用户
// 内存消耗：15.2 MB, 在所有 C++ 提交中击败了22.84% 的用户
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    map<long, int> m;//只记录最新一次的idx
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i - j > k)m.erase(nums[j++]);
        auto a = m.lower_bound((long long)nums[i] - t);
        if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
        m[nums[i]] = i;
    }
    return false;
}

int main(){
    cout << 1 << endl;
}