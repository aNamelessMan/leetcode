#include<bits/stdc++.h>
using namespace std;

// 执行用时：420 ms, 在所有 C++ 提交中击败了34.22% 的用户
// 内存消耗：34.5 MB, 在所有 C++ 提交中击败了42.25% 的用户
//局部最优就是全局最优  贪心算法
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int n = points.size();
    if(n == 0)return 0;
    int res = 1, end = points[0][1];
    for(int i = 1; i < n; i++){
        if (points[i][0] <= end) {
            end = min(end, points[i][1]);
        } else {
            ++res;
            end = points[i][1];
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}