#include<bits/stdc++.h>
using namespace std;

// 执行用时：124 ms, 在所有 C++ 提交中击败了15.59% 的用户
// 内存消耗：12.2 MB, 在所有 C++ 提交中击败了22.15%
//套用第84题代码，将每一层视为柱状图的底层，计算遍历后取最大值
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

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty())return 0;
    int res = 0, m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++){//每一层作为底部
        vector<int> heights;
        for(int j = 0; j < n; j++){
            int k = i, n1 = 0;
            while(k > -1 && matrix[k][j] == '1'){
                n1++;
                k--;
            }
            heights.push_back(n1);
        }
        res = max(res, largestRectangleArea(heights));
    }
    return res;
}

int main(){
    cout << 1 << endl;
}