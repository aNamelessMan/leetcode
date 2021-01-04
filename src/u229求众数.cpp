#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了90.17% 的用户
// 内存消耗：15.8 MB, 在所有 C++ 提交中击败了41.73% 的用户
//解法同169题，摩尔投票法
//最多只能有两个符合条件的
//使用投票法的核心是找出两个候选数进行投票，需要两遍遍历，第一遍历找出两个候选数，
//第二遍遍历重新投票验证这两个候选数是否为符合题意的数即可
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size(), lb = n / 3;
    for(auto num:nums){
        if(num == a)cnt1++;
        else if(num == b)cnt2++;
        else if(cnt1 == 0){a = num;cnt1 = 1;}
        else if(cnt2 == 0){b = num;cnt2 = 1;}
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(auto num:nums){
        if(num == a)cnt1++;
        else if(num == b)cnt2++;
    }
    if(cnt1 > lb)res.push_back(a);
    if(cnt2 > lb)res.push_back(b);
    return res;
}

// 执行用时：52 ms, 在所有 C++ 提交中击败了10.93% 的用户
// 内存消耗：15.9 MB, 在所有 C++ 提交中击败了19.93% 的用户
//暴力解法
vector<int> BFmajorityElement(vector<int>& nums) {
    int n = nums.size(), lb = n / 3;
    unordered_set<int> res;
    unordered_map<int, int>m;//每个数的出现次数
    for(auto i:nums){
        m[i]++;
        if(m[i] > lb)res.insert(i);
    }
    return vector<int>(res.begin(), res.end());
}

int main(){
    cout << 1 << endl;
}