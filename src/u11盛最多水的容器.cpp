#include<bits/stdc++.h>
using namespace std;

// 执行用时：84 ms, 在所有 C++ 提交中击败了12.01% 的用户
// 内存消耗：57.7 MB, 在所有 C++ 提交中击败了5.09% 的用户
//2021.3.9二刷还是不会写...
int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1, res = (r - l) * min(height[l], height[r]);
    /*面积等于  较短边长度 * 距离，
    因此想要获得更大面积，必须改变较短的边，因为无论我们向内移动多少格长边，短边不变，距离减小，面积只会减少，
    因此不用再考虑短边作为边界的情况，问题规模减一，继续归纳
    */
    while(l < r){
        if(height[l] < height[r]){
            l++;
        }else{
            r--;
        }
        res = max(res, (r - l) * min(height[l], height[r]));
    }
    return res;
}

// 执行用时：44 ms, 在所有 C++ 提交中击败了5.04% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了5.02% 的用户
int fstmaxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int res = 0;
    while(i < j){
        res = max(res, min(height[i], height[j]) * (j - i));
        height[i] < height[j]?i++:j--;//当h[i]和h[j]相等时，移动谁是无所谓的
                                    //因为如果要对res产生影响在距离减少的前提下，i和j一定都会往里移动，先后没有影响
    }
    return res;
}

int main(){
    cout << 1 << endl;
}