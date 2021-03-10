#include <bits/stdc++.h>
#include "../dataStruc/vecOps.hpp"
using namespace std;

//类似于逆序对，归并排序
//排序的是下标数组，nums不变，有点绕，思路是一样的
void merge(vector<int>& nums, vector<int> &res, vector<int> &idx, int l, int mid, int r){
    int p1 = l, p2 = mid + 1;
    queue<int> q;
    while(p1 != mid + 1 || p2 != r + 1){
        if(p1 == mid + 1){
            q.push(idx[p2]);
            p2++;
        }else if(p2 == r + 1){
            res[idx[p1]] += p2 - (mid + 1);
            q.push(idx[p1]);
            p1++;
        }else{
            if(nums[idx[p1]] <= nums[idx[p2]]){//此处必须有=，不然会把相等值计算进去，题目要求严格小于
                res[idx[p1]] += p2 - (mid + 1);
                q.push(idx[p1]);
                p1++;
            }else{
                q.push(idx[p2]);
                p2++;
            }
        }
    }
    for(int i = l; i <= r; i++){
        idx[i] = q.front();
        q.pop();
    }
}

void mergesort(vector<int>& nums, vector<int> &res, vector<int> &idx, int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergesort(nums, res, idx, l, mid);
        mergesort(nums, res, idx, mid + 1, r);
        merge(nums, res, idx, l, mid, r);
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;
    vector<int> res(n);
    vector<int> idx(n);
    for(int i = 0; i < n; i++)idx[i] = i;
    mergesort(nums, res, idx, l, r);
    return res;
}

int main(){
    vector<int> nums{5, 2, 6, 1};
    printVector(countSmaller(nums));
    cout << "print sth." << endl;
}