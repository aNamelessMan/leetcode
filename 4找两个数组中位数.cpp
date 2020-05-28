  /*
  执行用时 :20 ms, 在所有 C++ 提交中击败了71.92% 的用户
内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
  
  #include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k1 = nums1.size() - 1;
        int k2 = nums2.size() - 1;

        int total = nums1.size() + nums2.size();
        int mid = total / 2;
        int res = 0;
        if(2*mid < total){
            for(int i = 0;i < mid+1;++i){
                if(k1 == -1){res = nums2[k2];k2--;}
                else if(k2 == -1){res = nums1[k1];k1--;}
                else{
                    if(nums1[k1] > nums2[k2]){ res = nums1[k1];k1--;}
                    else{ res = nums2[k2];k2--;}
                }
            }
            return res;
        }
        else{
            int midnext = 0;
            for(int i = 0;i < mid;++i){
                if(k1 == -1){res = nums2[k2];k2--;}
                else if(k2 == -1){res = nums1[k1];k1--;}
                else{
                    if(nums1[k1] > nums2[k2]){ res = nums1[k1];k1--;}
                    else{ res = nums2[k2];k2--;}
                }
            }
                if(k1 == -1){midnext = nums2[k2];}
                else if(k2 == -1){midnext = nums1[k1];}
                else{
                    midnext  = nums1[k1] > nums2[k2] ? nums1[k1]:nums2[k2];
                }            
            return ((double)res + midnext)/2;
        }
    }
};

    int main(){
        vector<int> sz1 = {1,2};
        vector<int> sz2 = {-1,3};
        Solution solution;
        double res = solution.findMedianSortedArrays(sz1,sz2);
        cout << res << endl;
    }