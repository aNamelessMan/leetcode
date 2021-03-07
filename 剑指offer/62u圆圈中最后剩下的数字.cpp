#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.85% 的用户
// 内存消耗：8.6 MB, 在所有 C++ 提交中击败了31.09% 的用户
int lastRemaining(int n, int m) {//n是环长度,m是删除的下标(从1开始)
    if(n == 1)return 0;
    return (lastRemaining(n - 1, m) + m) % n;//映射回原下标
}

int main(){
    cout << "print sth." << endl;
}