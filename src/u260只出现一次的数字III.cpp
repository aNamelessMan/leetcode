#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了97.77% 的用户
// 内存消耗：10 MB, 在所有 C++ 提交中击败了74.54% 的用户
vector<int> singleNumber(vector<int>& nums) {
    long diff = 0;
    for(auto &num:nums){
        diff ^= num;
    }
    //假设结果是[a b]
    //此时diff是a^b
    diff &= -diff;//diff的二进制只有一个1，这个1表示的是a b从右往左看，第一个不相同的bit
    vector<int> res(2, 0);
    for(auto &num:nums){
        //根据diff中的那一位是否为1将nums分为两组，相同的数字一定分在一组，因此最后异或为0，结果中的两个数一定是两组的最后结果
        if(num & diff)res[0] ^= num;
        else res[1] ^= num;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}