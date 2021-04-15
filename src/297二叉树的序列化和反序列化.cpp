#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：60 ms, 在所有 C++ 提交中击败了49.12% 的用户
// 内存消耗：30.1 MB, 在所有 C++ 提交中击败了75.12% 的用户
// 2021.4.15二刷
class myCodec {
public:

    void preorder(TreeNode *root, string &str){
        if(!root)str += "# ";
        else{
            str += to_string(root->val);
            str += " ";
            preorder(root->left, str);
            preorder(root->right, str);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }

    TreeNode* reverpreorder(istringstream &str){
        string t;
        str >> t;
        TreeNode *res = nullptr;
        if(t != "#"){
            res = new TreeNode(atoi(t.c_str()));
            res->left = reverpreorder(str);
            res->right = reverpreorder(str);
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream str(data);
        TreeNode *res = reverpreorder(str);
        return res;
    }
};

// 执行用时：52 ms, 在所有 C++ 提交中击败了97.97% 的用户
// 内存消耗：32.6 MB, 在所有 C++ 提交中击败了48.85% 的用户
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

int main(){
    cout << 1 << endl;
}