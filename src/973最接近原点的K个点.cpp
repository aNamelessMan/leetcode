#include<bits/stdc++.h>
using namespace std;

// 执行用时：436 ms, 在所有 C++ 提交中击败了43.04% 的用户
// 内存消耗：59 MB, 在所有 C++ 提交中击败了19.23% 的用户
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    multimap<int, vector<int>> dpos;//距离可能相等，所以需要multimap
// 否则遇到重复关键字报错如下：
// terminate called after throwing an instance of 'std::bad_alloc'
// what():  std::bad_alloc
// 已放弃 (核心已转储)
    vector<vector<int>> res;
    for(auto &p:points){
        int dis = pow(p[0], 2) + pow(p[1], 2);
        dpos.insert({dis, p});
    }
    auto iter = dpos.begin();
    for(int i = 0; i < K; i++){
        res.push_back(iter->second);
        iter++;
    }
    return res;
}

int main(){
    vector<vector<int>> points;
    points.push_back({0, 1});
    points.push_back({1, 0});
    kClosest(points, 2);

    cout << 1 << endl;
}