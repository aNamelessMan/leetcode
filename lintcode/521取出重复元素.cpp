#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 34.20% 的提交!
int deduplication(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    auto iter = unique(nums.begin(), nums.end());//注意unique消除的是相邻的重复项，所以要先排序，返回的是尾后迭代器
    int res = 0;
    for(auto i = nums.begin(); i != iter; i++){
        res++;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}