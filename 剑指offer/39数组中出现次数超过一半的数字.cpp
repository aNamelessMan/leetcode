#include <bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了79.24% 的用户
// 内存消耗：18.3 MB, 在所有 C++ 提交中击败了59.41% 的用户
int majorityElement(vector<int>& nums) {
    int res = nums[0], cnt = 1, n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] == res)cnt++;
        else{
            if(cnt == 0){
                res = nums[i];
                cnt = 1;
            }else{
                cnt--;
            }
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}