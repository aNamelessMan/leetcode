#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了88.65% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
int hIndex(vector<int>& citations) {
    if(citations.empty())return 0;
    sort(citations.begin(),citations.end());
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