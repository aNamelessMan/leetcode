#include<bits/stdc++.h>
using namespace std;

// 执行用时：128 ms, 在所有 C++ 提交中击败了40.12% 的用户
// 内存消耗：61.6 MB, 在所有 C++ 提交中击败了38.31% 的用户
//使用单调栈
int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    stack<int> stk;
    heights.push_back(-1);//加入这个元素是为了强制在结束时清空栈，防止结束时仍有情况未计算
    for(int i = 0, n = heights.size(); i < n; i++){
        if(stk.empty() || heights[stk.top()] <= heights[i]){//维护递增栈
            stk.push(i);
        }else{
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                //将栈顶出栈，栈顶的前一个元素是在该元素左边且低于它的最近的元素，将要入栈的元素i是在该元素右边且低于它的最近的元素，这样就能计算以该元素高度为高的矩形面积
                int t = stk.top();
                stk.pop();
                int l;
                if(stk.empty()){
                    l = -1;
                }else{
                    l = stk.top();
                }
                res = max(res, heights[t] * (i - l - 1));
            }
            stk.push(i);
        }
    }
    return res;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了99.78% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了95.10% 的用户
int firstlargestRectangleArea(vector<int>& heights) {
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