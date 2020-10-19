#include<bits/stdc++.h>
using namespace std;
// 执行用时：40 ms, 在所有 C++ 提交中击败了92.18% 的用户
// 内存消耗：14.4 MB, 在所有 C++ 提交中击败了19.80% 的用户
bool isSmaller(const vector<int> &vi1, const vector<int> &vi2){
    return vi1[0] < vi2[0];
}
//先排序
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() < 2)return intervals;

    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end(), isSmaller);
    res.push_back(intervals[0]);

    for(int i = 1; i < (int)intervals.size(); i++){
        int n = res.size() - 1;
        if(intervals[i][0] <= res[n][1])res[n][1] = min(res[n][1], intervals[i][1]);
        else res.push_back(intervals[i]);
    }
    return res;
}

int main(){
    vector<vector<int>> intv{{1,3},{2,6},{8,10},{15,18}};
    merge(intv);
    cout << 1 << endl;
}