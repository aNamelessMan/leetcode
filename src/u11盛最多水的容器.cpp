#include<bits/stdc++.h>
using namespace std;
// 执行用时：44 ms, 在所有 C++ 提交中击败了5.04% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了5.02% 的用户
int maxArea(vector<int>& height) {
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