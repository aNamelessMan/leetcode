#include<bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了86.37% 的用户
// 内存消耗：15 MB, 在所有 C++ 提交中击败了77.72% 的用户
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> h;
    vector<vector<int>> res;
    multiset<int> m;
    int pre = 0, cur = 0;
    for (auto &a : buildings) {//a[0]左边界 a[1]右边界  a[2]高度
        h.push_back({a[0], -a[2]});
        h.push_back({a[1], a[2]});
    }
    sort(h.begin(), h.end());//按左右边界排序
    m.insert(0);
    for (auto &a : h) {//按从左到右的顺序处理
        if (a.second < 0) m.insert(-a.second);//说明是左边界
        else m.erase(m.find(a.second));//说明是右边界，此段高度的建筑到此结束，所以取出一个高度为a.second的值
        cur = *m.rbegin();//m是有序集合，因此cur是当前最低的高度
        if (cur != pre) {//如果不同，说明当前高度比之前的高度更高
            res.push_back({a.first, cur});
            pre = cur;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}