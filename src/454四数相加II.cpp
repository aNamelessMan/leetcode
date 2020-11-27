#include<bits/stdc++.h>
using namespace std;

// 执行用时：748 ms, 在所有 C++ 提交中击败了17.65% 的用户
// 内存消耗：63.4 MB, 在所有 C++ 提交中击败了5.01% 的用户
//复杂度O(N^2)  想到了之前华为软挑dfs的剪枝 所以就写了这个解法
//貌似这个就是最快的解法
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> first2;//前两个数组中取出的二元组   的和    的个数
    unordered_map<int, int> second2;
    int n = A.size();
    if(n == 0)return 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            first2[A[i] + B[j]]++;
            second2[C[i] + D[j]]++;
        }
    }
    int res = 0;
    for(auto &p:first2){
        res += p.second * second2[-p.first];
    }
    return res;
}

int main(){
    vector<int> A = {0};
    vector<int> B = {0};
    vector<int> C = {0};
    vector<int> D = {0};
    fourSumCount(A, B, C, D);
    cout << 1 << endl;
}