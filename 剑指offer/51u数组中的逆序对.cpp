#include <bits/stdc++.h>
using namespace std;

// 执行用时：768 ms, 在所有 C++ 提交中击败了11.89% 的用户
// 内存消耗：397.4 MB, 在所有 C++ 提交中击败了4.99% 的用户
//归并排序过程中计算逆序对个数
void merge(vector<int>& nums, int l, int h, int &res){
    int mid = (l + h) / 2, p1 = l, p2 = mid + 1;
    queue<int> q;//每次将p2入队时，加上p1未入队的个数，因为这个p2和剩余的p1都是逆序对
    while(p1 != mid + 1 || p2 != h + 1){
        if(p1 == mid + 1){
            q.push(nums[p2]);
            p2++;//剩余p1为0不用加了
        }else if(p2 == h + 1){
            q.push(nums[p1]);
            p1++;
        }else{
            if(nums[p1] > nums[p2]){
                q.push(nums[p2]);
                p2++;
                res += mid + 1 - p1;//更新逆序对个数
            }else{//等于时优先放p1，确保放p2时不用考虑相等值
                q.push(nums[p1]);
                p1++;
            }
        }
    }
    for(int i = l; i <= h; i++){
        nums[i] = q.front();
        q.pop();
    }
}

void mergesort(vector<int>& nums, int l, int h, int &res){
    if(l < h){
        int mid = (l + h) / 2;
        mergesort(nums, l, mid, res);
        mergesort(nums, mid + 1, h, res);
        merge(nums, l, h, res);
    }
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)return 0;
    int res = 0;
    mergesort(nums, 0, n - 1, res);
    return res;
}

int main(){
    cout << "print sth." << endl;
}