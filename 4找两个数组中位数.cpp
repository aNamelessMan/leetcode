#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double errorfindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//不满足复杂度为O(log(m+n))
      /*
    执行用时 :20 ms, 在所有 C++ 提交中击败了71.92% 的用户
    内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    */
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

/*
假设第一个数组长度为m，第二个为n，那么在m+n为偶数时，就是找到两个数组里第(m+n)/2和第(m+n+2)/2的均值
                                                                                        在奇数情况下，应该找第(m+n+1)/2的值
                                                                                        但是利用整数除法取整，我们可以统一两种情况为求第(m+n+1)/2和(m+n+2)/2的均值
        设i和j分别是nums1和nums2的当前下标，表明nums1的第i个之前的  和nums2的第j个之前的  都不可能是第k小的值
            都从0开始，也就是从最小往第K开始查找，先比较nums1[k/2 - 1]和nums2[k/2 - 1]大小，谁更小就将谁的下标加k/2，
            因为小的那k/2个数里不可能有第k小的数，因为最大也只可能是第k-1小，排除掉了k/2个因此将k减去k/2
            再递归的去在未被排除的里找第k/2小即可

            注意base    case不要漏！！！当k = 1时，只要返回两数组当前下标中的最小值即可

        这里有几个边界情况：
            1.如果某个数组下标在函数起始就越界，说明都已经排除直接在另一个数组里的当前下标加k即是结果
            2.如果某个数组的下标加上k/2后越界了，就肯定不能将它进行排除，所以设为最大值以避免下标改动
也就是用i，j两个游标来标记为排除的起始位置，用K指示需要找剩余数组中第K大的数
*/
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了97.21% 的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
        int m = nums1.size();
        int n = nums2.size();        
        return  (findKth(nums1,0,nums2,0,(m+n+1)/2) + findKth(nums1,0,nums2,0,(m+n+2)/2))/2.0;
    }
    int findKth(vector<int>& nums1,int i,vector<int>& nums2,int j,int k){
        if(i >= nums1.size())return nums2[j + k - 1];
        if(j >= nums2.size())return nums1[i + k - 1];
        //basecase不要忘！！！
        if(k == 1)return    min(nums1[i],nums2[j]);

        int mindval1 = ((i + k/2 -1) >= nums1.size())?INT_MAX:nums1[i + k/2 -1];
        int mindval2 = ((j + k/2 -1) >= nums2.size())?INT_MAX:nums2[j + k/2 -1];
        if(mindval1 < mindval2)//如果相等其实随便排除哪一组都行
            return  findKth(nums1,i+k/2,nums2,j,k - k/2);//注意此处k - k/2不能替换为k/2因为在k为奇数时并不相等
        else
            return  findKth(nums1,i,nums2,j+k/2,k - k/2);
    }

};

    int main(){
        vector<int> sz1 = {1,2};
        vector<int> sz2 = {3,4};
        Solution solution;
        double res = solution.findMedianSortedArrays(sz1,sz2);
        cout << res << endl;
    }