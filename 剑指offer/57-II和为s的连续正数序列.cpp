#include <bits/stdc++.h>
#include "../dataStruc/vecOps.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了16.54% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了69.32% 的用户
//滑动窗口  O(n)不知道为什么这么慢
vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    vector<int> t{1, 2};
    int cursum = 3, l = 1, r = 3;
    while(r < target){
        while(cursum < target && r < target){
            cursum += r;
            t.push_back(r);
            r++;
        }
        while(cursum > target && 2 < r - l){//至少保证要有两个数
            cursum -= l;
            t.erase(t.begin());
            l++;
        }
        if(r - l == 2 && cursum > target)break;//当只有两个数却大于target时说明不会再有了，退出
        if(cursum == target){
            res.push_back(t);

            cursum += r;
            t.push_back(r);
            r++;
        }
    }
    return res;
}

int main(){
    printVecOfVec(findContinuousSequence(9));
}