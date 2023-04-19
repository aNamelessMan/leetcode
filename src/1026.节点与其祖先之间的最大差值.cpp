
#include <tuple>
#include <iostream>

using namespace std;
using std::tuple;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int res = -1;
    tuple<int, int> maxAncestorDiff(TreeNode* root, int justforoverload) {
        if(root->left == nullptr && root->right == nullptr){
            return tuple<int, int>(root->val, root->val);
        }else if(root->left == nullptr && root->right != nullptr){
            tuple<int, int>r = maxAncestorDiff(root->right, 1);
            res = max(res, max(abs(root->val - get<1>(r)), abs(get<0>(r) - root->val)));
            return tuple<int, int>(max(root->val, get<0>(r)), min(root->val, get<1>(r)));
        }else if(root->left != nullptr && root->right == nullptr){
            tuple<int, int>l = maxAncestorDiff(root->left, 1);
            res = max(res, max(abs(root->val - get<1>(l)), abs(get<0>(l) - root->val)));
            return tuple<int, int>(max(root->val, get<0>(l)), min(root->val, get<1>(l)));
        }else{
            tuple<int, int>l = maxAncestorDiff(root->left, 1);
            res = max(res, max(abs(root->val - get<1>(l)), abs(get<0>(l) - root->val)));
            tuple<int, int>r = maxAncestorDiff(root->right, 1);
            res = max(res, max(abs(root->val - get<1>(r)), abs(get<0>(r) - root->val)));
            return tuple<int, int>(max(root->val, max(get<0>(l), get<0>(r))), min(root->val, min(get<1>(l), get<1>(r))));
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        maxAncestorDiff(root, 1);
        return res;
    }
};

int main(){
    cout << "case1" << endl;
    TreeNode n3 = TreeNode(3);
    TreeNode n0 = TreeNode(0, &n3, nullptr);
    TreeNode n2 = TreeNode(2, nullptr, &n0);
    TreeNode n1 = TreeNode(1, nullptr, &n2);
    Solution s;
    s.maxAncestorDiff(&n1);
    cout << s.res << endl;
}
