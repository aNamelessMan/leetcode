#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    int n = nums.size();
    int res = 0;
    if(n < 2)return res;
    for(int i = 0; i < n; i++){
        cnt[nums[i]]++;
    }
    for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
        while(iter->second){
            auto oiter = cnt.find(k - iter->first);
            if(oiter != cnt.end() && oiter->second && iter != oiter){
                oiter->second--;
                iter->second--;
                res++;
            }else if(oiter != cnt.end() && oiter->second >= 2&& iter == oiter){
                iter->second -= 2;
                res++;
            }else{
                break;
            }
        }
    }
    return res;
}

int main(){
    // vector<int> nums1 = {1, 2, 3, 4};
    // cout << maxOperations(nums1, 5) << endl;
    vector<int> nums2 = {3, 1, 3, 4, 3};
    cout << maxOperations(nums2, 6) << endl;
}