#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.61% 的用户
// 内存消耗：13.3 MB, 在所有 C++ 提交中击败了90.91% 的用户
//看的别人的解法不太懂，还不如自己的解法，虽然繁琐，但是简单
int lbs(vector<int>& nums, int target, int l, int r){
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[mid] < target){
            l = mid + 1;
        }else if(nums[mid] == target){
            r = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int rbs(vector<int>& nums, int target, int l, int r){
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(nums[mid] > target){
            r = mid - 1;
        }else if(nums[mid] == target){
            l = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    vector<int> res(2, -1);
    if(r < 0)return res;
    int lb = lbs(nums, target, l, r);
    int rb = rbs(nums, target, l, r);
    res[0] = nums[lb] != target?-1:lb;
    res[1] = res[0] == -1 || nums[rb] != target?-1:rb;
    return res;
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了98.53% 的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了18.79% 的用户
//写的很繁琐，但是思路很简单
int rbs(int l, int h, int target, vector<int>& nums){
    if(l == h){
        if(nums[l] == target)
            return l;
        else
            return -1;
    }
    if(l == h - 1){
        if(nums[h] == target)
            return h;
        if(nums[l] == target)
            return l;
        return -1;
    }
    if(l > h)return -1;
    int mid = (h - l) / 2 + l;
    if(nums[mid] > target){
        return rbs(l, mid - 1, target, nums);
    } else if(nums[mid] < target){
        return rbs(mid + 1, h, target, nums);
    }else{
        return rbs(mid, h, target, nums);
    }
}

int lbs(int l, int h, int target, vector<int>& nums){
    if(l == h){
        if(nums[l] == target)
            return l;
        else
            return -1;
    }
    if(l == h - 1){
        if(nums[l] == target)
            return l;
        if(nums[h] == target)
            return h;
        return -1;
    }
    if(l > h)return -1;
    int mid = (h - l) / 2 + l;
    if(nums[mid] > target){
        return lbs(l, mid - 1, target, nums);
    } else if(nums[mid] < target){
        return lbs(mid + 1, h, target, nums);
    }else{
        return lbs(l, mid, target, nums);
    }
}

vector<int> firstsearchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)return {-1, -1};
    return {lbs(0, n - 1, target, nums), rbs(0, n - 1, target, nums)};
}

// 执行用时：20 ms, 在所有 C++ 提交中击败了76.68% 的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了5.30% 的用户
//不是严格logn先过了再说，有空看题解 https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
int bs(vector<int>& nums, double target, int b, int e){
    if(b > e)return -1;
    int mid = (b + e) / 2;
    if(nums[mid] == target)return mid;
    if(nums[mid] > target){
        return bs(nums, target, b, mid - 1);
    }else{
        return bs(nums, target, mid + 1, e);
    }
}

vector<int> PresearchRange(vector<int>& nums, int target) {
    int idx = bs(nums, target, 0, nums.size() - 1);
    if(idx == -1)return {-1, -1};
    int left = idx, right = idx;
    while (left > 0 && nums[left - 1] == nums[idx]) --left;
    while (right < (int)nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
    return {left, right};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = searchRange(nums, 8);
    nums = {2, 2};
    res = searchRange(nums, 3);
    cout << 1 << endl;
}