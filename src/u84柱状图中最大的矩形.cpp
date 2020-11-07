#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了99.78% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了95.10% 的用户
int largestRectangleArea(vector<int>& heights) {
    if(heights.empty())return 0;
    int n = heights.size();
    if(n == 1)return heights[0];
    int res = 0;
    for(int i = 0; i < n; i++){
        if(i + 1 < n && heights[i] <= heights[i + 1])continue;//只尝试遍历比后面更高的块和最后一块
                                                              //因为比后面更小的块一定会有比他能组成的更大矩形
        int minh = heights[i];
        for(int j = i; j > -1; j--){//遍历每一块
            minh = min(minh, heights[j]);
            int w = i - j + 1;
            int area = w * minh;
            res = max(res, area);
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}