#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int m = nums1.size(), n = nums2.size();
    int n1mx = 6 * m, n1mn = m, n2mx = 6 * n, n2mn = n;
    if(n1mx < n2mn || n1mn > n2mx)return -1;
    int cnt = 0;
    if(sum1 > sum2){
        int r1 = m - 1, l2 = 0;
        while(1){
            int c1 = r1 >= 0?nums1[r1] - 1:0, c2 = l2 < n?6 - nums2[l2]:0, c = sum1 - sum2;
            if(c1 > c2){
                if(c1 >= c)return cnt + 1;
                sum1 -= c1;
                r1--;
            }else{
                if(c2 >= c)return cnt + 1;
                sum2 += c2;
                l2++;
            }
            cnt++;
        }
    }else if(sum1 < sum2){
        int r2 = n - 1, l1 = 0;
        while(1){
            int c1 = l1 < n?6 - nums1[l1]:0, c2 = r2 >= 0?nums2[r2] - 1:0, c = sum2 - sum1;
            if(c1 > c2){
                if(c1 >= c)return cnt + 1;
                sum1 += c1;
                l1++;
            }else{
                if(c2 >= c)return cnt + 1;
                sum2 -= c2;
                r2--;
            }
            cnt++;
        }
    }else{
    }
    return cnt;
}

int main(){
    // vector<int> n1 = {5,6,4,3,1,2};
    // vector<int> n2 = {6,3,3,1,4,5,3,4,1,3,4};
    vector<int> n1 = {5,2,1,5,2,2,2,2,4,3,3,5};
    vector<int> n2 = {1,4,5,5,6,3,1,3,3};
    cout << minOperations(n1, n2) << endl;
}