#include<bits/stdc++.h>
using namespace std;
// 执行用时：56 ms, 在所有 C++ 提交中击败了11.47% 的用户
// 内存消耗：23.8 MB, 在所有 C++ 提交中击败了11.77% 的用户
//空间复杂度O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    for(int i = 1; i < n; i++){
        res[i] = res[i - 1] * nums[i - 1];
    }
    //上面循环完后res中存的是前缀和
    int right = 1;//用right暂存当前节点的后缀和
    for(int i = n - 2; i > -1; i--){
        right *= nums[i + 1];
        res[i] *= right;
    }
    return res;
}

// 执行用时：48 ms, 在所有 C++ 提交中击败了17.87% 的用户
// 内存消耗：24.8 MB, 在所有 C++ 提交中击败了5.07% 的用户
//时间复杂度和空间复杂度都是O(n)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1);
    vector<int> suf(n, 1);
    vector<int> res(n, 1);
    pre[0] = nums[0];
    suf[n - 1] = nums[n - 1];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i - 1] * nums[i];
        suf[n - i - 1] = suf[n - i] * nums[n - i - 1];
    }
    res[0] = suf[1];
    res[n - 1] = pre[n - 2];
    for(int i = 1; i < n - 1; i++){
        res[i] = pre[ i - 1] * suf[i + 1];
    }
    return res;
}

int main(){
    cout << 1 << endl;
}