#include<bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了82.57% 的用户
// 内存消耗：36.2 MB, 在所有 C++ 提交中击败了17.15% 的用户
//采用先序遍历递归思路就很简单，因为先序遍历左子树和右子树在序列化后时不会交叉的，就顺序遍历递归，先左后右即可
class Codec {
public:
    string dfsse(TreeNode* root){
        string res;
        if(!root){
            res += '#';
            res += ' ';
            return res;
        }else{
            res += to_string(root->val);
            res += ' ';
        }
        return res + dfsse(root->left) + dfsse(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfsse(root);
    }

    TreeNode* dfsde(istringstream &ins){
        TreeNode* res = nullptr;
        string t;
        ins >> t;
        if(t == "#")return res;
        else{
            res = new TreeNode(atoi(t.c_str()));
        }
        res->left = dfsde(ins);
        res->right = dfsde(ins);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ins(data);
        return dfsde(ins);
    }
};
