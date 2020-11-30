#include<bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了42.21% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了9.36% 的用户
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> n1, n2;
    vector<int> res;
    for(auto i: nums1){
        n1.insert(i);
    }
    for(auto i: nums2){
        n2.insert(i);
    }

    for(auto &i:n1){
        if(n2.count(i))res.push_back(i);
    }

    return res;
}

int main(){
    cout << 1 << endl;
}