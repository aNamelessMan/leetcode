#include <bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了81.56% 的用户
// 内存消耗：15.8 MB, 在所有 C++ 提交中击败了52.03% 的用户
vector<int> singleNumbers(vector<int>& nums) {
    //因为其他数字都出现了两次，因此nums异或一遍的结果的就是这两个数异或结果，这结果中一定有至少一位为1，根据这位是否为1把nums分成两组，出现一次的两个数一定分别在这两组
    int res = 0;
    for(auto i: nums){
        res ^= i;
    }
    int cnt = 0;
    while(res % 2 == 0){
        cnt++;
        res /= 2;
    }//右移cnt位后二进制末尾为1
    vector<int> ans(2, 0);
    for(int i:nums){
        if((i >> cnt) % 2)ans[0] ^= i;//注意>>操作不会改变变量值，只有把结果赋给变量才会改变变量
        else ans[1] ^= i;
    }
    return ans;
}

int main(){
    vector<int> nums{1,2,10,4,1,4,3,3};
    singleNumbers(nums);
    cout << "print sth." << endl;
}