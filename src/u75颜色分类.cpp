#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.5 MB, 在所有 C++ 提交中击败了5.19% 的用户

//设置两个指针一个指向0的终点，一个指向2的起点，扫描到0或1时交换数字并更新指针，扫到1不动
void sortColors(vector<int>& nums) {
    if(nums.size() < 2)return;
    int f = 0, b = nums.size() - 1;

    //注意到i一定是大于等于f，小于等于b
    for(int i = 0; i <= b; i++){
        if(nums[i] == 1)continue;
        else if(nums[i] == 0){
            nums[i] = nums[f];//i>=f，所以换过来的一定是1，不用动
            nums[f] = 0;
            f++;
        }else{
            nums[i] = nums[b];
            nums[b] = 2;
            b--;
            i--;//注意换过来的可能是2，所以i保持不动，再处理一次
        }
    }
}

int main(){
    vector<int> nums({2,0,2,1,1,0});
    sortColors(nums);
    cout << 1 << endl;
}