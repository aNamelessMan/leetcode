#include<bits/stdc++.h>
using namespace std;
// 执行用时：52 ms, 在所有 C++ 提交中击败了26.76% 的用户
// 内存消耗：14.2 MB, 在所有 C++ 提交中击败了6.13% 的用户
bool isGreater(const vector<int> &v1, const vector<int> &v2){
    return v1[1] > v2[1];
}
vector<int> BFtopKFrequent(vector<int>& nums, int k) {//复杂度等于排序O(nlogn)
    vector<int> res;
    map<int, int>freq;
    for(auto &num:nums)
        freq[num]++;
    vector<vector<int>> f;
    for(auto &p:freq)
        f.push_back({p.first, p.second});
    sort(f.begin(), f.end(), isGreater);
    for(int i = 0; i < k; i++){
        res.push_back(f[i][0]);
    }
    return res;
}
// 执行用时：36 ms, 在所有 C++ 提交中击败了84.94% 的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了58.11% 的用户
//仅仅把数据结构vector修改成了priority_queue，复杂度会变吗？
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
}

int main(){
    cout << 1 << endl;
}