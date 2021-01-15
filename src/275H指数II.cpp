#include<bits/stdc++.h>
using namespace std;

//有序数组，对数复杂度，肯定是二分

// 执行用时：12 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：17.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
//复制粘贴274题的解法，一个字不改就能通过...复杂度应该是线性
//题目唯一的不同就是这题的数组已经排好序了
int hIndex(vector<int>& citations) {
    if(citations.empty())return 0;
    //sort(citations.begin(),citations.end());
    int n = citations.size();
    int m = min(citations[n - 1], n);
    for(int i = n - m; i < n; i++){
        if(citations[i] >= n - i)return n - i;
    }
    return 0;
}

int main(){
    cout << "print something." << endl;
}