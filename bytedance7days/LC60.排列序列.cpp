#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了67.19% 的用户
//(逆)康托展开    一种双射，可以用于hash
string getPermutation(int n, int k) {
    vector<int> f;//记录0到n-1的阶乘
    f.push_back(1);
    for(int i = 1; i < n; i++){
        f.push_back(f.back() * i);
    }

    vector<int> used;//用于标记1到n是否已经用过
    used.push_back(0);
    for(int i = 1; i <= n; i++){
        used.push_back(1);
    }

    string res;
    int r = k - 1, l;
    for(int i = n - 1; i >= 0; i--){
        l = r % f[i];
        r = r / f[i];
        int c = r + 1, iter = 0;
        while(c && iter <= n){
            if(used[iter]){
                c--;
            }
            iter++;
        }
        used[iter - 1] = 0;
        res += to_string(iter - 1);
        r = l;
    }
    return res;
}

// 执行用时：1008 ms, 在所有 C++ 提交中击败了12.19% 的用户
// 内存消耗：6.3 MB, 在所有 C++ 提交中击败了5.26% 的用户
//内置函数大法
string firstgetPermutation(int n, int k) {
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
    getPermutation(5, 96);
    cout << 1 << endl;
}