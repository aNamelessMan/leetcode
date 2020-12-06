#include<bits/stdc++.h>
#include "TreeNode.hpp"
#include "ListNode.hpp"
using namespace std;

// 执行用时：44 ms, 在所有 C++ 提交中击败了57.04% 的用户
// 内存消耗：32.8 MB, 在所有 C++ 提交中击败了6.31% 的用户
TreeNode* sortedArrayToBST(vector<int>& nums, int b, int e){
    if(b > e){
        return nullptr;
    }
    else if(b == e){
        TreeNode *root = new TreeNode(nums[b]);
        return root;
    }else if(b == e - 1){
        TreeNode *root = new TreeNode(nums[e]);
        root->left = new TreeNode(nums[b]);
        return root;
    }else if(b == e - 2){
        TreeNode *root = new TreeNode(nums[b + 1]);
        root->left = new TreeNode(nums[b]);
        root->right = new TreeNode(nums[e]);
        return root;
    }else{
        int mid = (b + e) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, b, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, e);
        return root;
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return sortedArrayToBST(nums, 0, n - 1);
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while(head){
        nums.push_back(head->val);
        head = head->next;
    }

    return sortedArrayToBST(nums);
}

int main(){
    cout << 1 << endl;
}