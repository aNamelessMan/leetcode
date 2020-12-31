#include<bits/stdc++.h>
using namespace std;

// 执行用时：36 ms, 在所有 C++ 提交中击败了60.43% 的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了84.68% 的用户
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int res = 0, n = intervals.size(), last = 0;//last是当前选中的范围最靠后的区间的下标
    sort(intervals.begin(), intervals.end());//按区间起始位置从小到大排序
    for(int i = 1; i < n; i++){
        if(intervals[i][0] < intervals[last][1]){//说明有重叠
            res++;
            //更新last，选择区间更靠前的那个
            if(intervals[i][1] < intervals[last][1])last = i;
        }else
            last = i;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}