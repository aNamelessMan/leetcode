#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了84.36% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了36.78% 的用户
//想到利用nums1后面的空置空间来归并就很简单了，看了题解才想到的...
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int nextInsert = m + n - 1;
    m--;
    n--;
    while(nextInsert >= 0){
        if(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[nextInsert] = nums1[m];
                m--;
                nextInsert--;
            }else{
                nums1[nextInsert] = nums2[n];
                n--;
                nextInsert--;
            }
        }else if(m >= 0){
            nums1[nextInsert] = nums1[m];
            m--;
            nextInsert--;
        }else{
            nums1[nextInsert] = nums2[n];
            n--;
            nextInsert--;
        }
    }
}

int main(){
    cout << 1 << endl;
}