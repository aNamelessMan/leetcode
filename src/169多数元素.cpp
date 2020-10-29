#include<bits/stdc++.h>
using namespace std;
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