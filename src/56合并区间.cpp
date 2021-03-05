#include<bits/stdc++.h>
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了64.97% 的用户
// 内存消耗：14.8 MB, 在所有 C++ 提交中击败了18.87% 的用户
//先按结束时间排序，然后逐个遍历与尾部比较， 尾部结束时间一定更早，只需判断与下一个开始时间是否重叠，重叠则合并区间
static bool cmp(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];//按结束时间由早到晚排序
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> res;
    for(int i = 0; i < n; i++){
        if(res.empty() || intervals[i][0] > res.back()[1]){
            res.push_back(intervals[i]);
        }else{
            vector<int> t = res.back();
            res.pop_back();
            res.push_back({min(intervals[i][0], t[0]), max(intervals[i][1], t[1])});
        }
    }
    return res;
}

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