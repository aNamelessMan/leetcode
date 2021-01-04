#include<bits/stdc++.h>
using namespace std;

// 执行用时：36 ms, 在所有 C++ 提交中击败了42.12% 的用户
// 内存消耗：19.7 MB, 在所有 C++ 提交中击败了5.12% 的用户
//参考229题摩尔投票法
int majorityElement(vector<int>& nums) {
    int n = nums.size(), lb = n / 2;
    int res = 0, cnt = 0;
    for(auto num:nums){
        if(num == res)cnt++;
        else if(cnt == 0){
            res = num;
            cnt = 1;
        }else{
            cnt--;
        }
    }
    return res;
}

// 执行用时：24 ms, 在所有 C++ 提交中击败了61.63% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了9.42% 的用户
int majorityElement(vector<int>& nums) {
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