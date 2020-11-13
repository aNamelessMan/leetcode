#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了83.28% 的用户
// 内存消耗：10.1 MB, 在所有 C++ 提交中击败了5.88% 的用户
//首先注意到结果只有可能在1到n+1之间，当nums刚好是1到n时才返回n + 1
//因此我们只需要考虑1到n+1即可，可以用nums本身来表示1到n是否出现
//将1到n放到对应的  nums[i - 1] 处 
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])//只处理1到n 并 防止死循环    终止条件是确保下标为nums[nums[i] - 1]里面存的是nums[i]
                                                                          //当遍历到nums[i] - 1时里面存的已经是 nums[i]就会直接跳过
            swap(nums[i], nums[nums[i] - 1]);//把nums[i]放到正确的地方
    }
    for(int i = 0; i < n; i++){
        if(nums[i] != i + 1)return i + 1;
    }
    return n + 1;
}

int main(){
    cout << 1 << endl;
}