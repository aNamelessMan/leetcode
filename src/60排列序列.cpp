#include<bits/stdc++.h>
using namespace std;

// 执行用时：1008 ms, 在所有 C++ 提交中击败了12.19% 的用户
// 内存消耗：6.3 MB, 在所有 C++ 提交中击败了5.26% 的用户
//内置函数大法
string getPermutation(int n, int k) {
    string res;
    for(int i = 0; i < n; i++){
        res.push_back('0' + i + 1);
    }
    int i = 0;
    while(i < k - 1){
        next_permutation(res.begin(), res.end());
        i++;
    }
    return res;
}
//还可以把next_permutation换成31题的代码，输入改一下即可，但是会更慢...
// 执行用时：1936 ms, 在所有 C++ 提交中击败了5.01% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了31.53% 的用户

int main(){
    cout << 1 << endl;
}