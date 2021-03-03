#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了68.97% 的用户
bool verifyPostorder(vector<int>& postorder, int s, int e){
    //后序遍历序列的最后一个元素一定是根节点元素，左子树的所有元素都要大于根节点， 右子树的所有元素都小于根节点，根据这个性质划分左右，并判断是否成功，递归下去
    if(s == e || s == e - 1 || s > e)return true;
    int root = postorder[e];
    int i;
    for(i = 0; i < e; i++){
        if(postorder[i] > root)break;
    }

    int mid = i;
    for(; i < e; i++){
        if(postorder[i] < root)return false;
    }
    return verifyPostorder(postorder, s, mid - 1) && verifyPostorder(postorder, mid, e - 1);
}

bool verifyPostorder(vector<int>& postorder) {
    int n = postorder.size();
    if(n == 0)return true;
    return verifyPostorder(postorder, 0, n - 1);
}

int main(){
    cout << "print sth." << endl;
}