#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了44.33% 的用户
// 内存消耗：19.2 MB, 在所有 C++ 提交中击败了28.79% 的用户
//参考229题摩尔投票法
int majorityElement(vector<int>& nums) {
    int cnt = 1, res = nums[0], n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] == res){
            cnt++;
        }else{
            if(cnt == 0){
                res = nums[i];
                cnt = 1;
            }else{
                cnt--;
            }
        }
    }
    return res;
}

// 执行用时：24 ms, 在所有 C++ 提交中击败了61.63% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了9.42% 的用户
int BFmajorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for(auto &i:nums){
        m[i]++;
    }
    int t = nums.size()/2, res;
    for(auto &p:m){
        if(p.second > t){
            res = p.first;
            break;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}