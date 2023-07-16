#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int> F(n + 1, 0);
        F[0] = 0;
        F[1] = 1;
        for(int i = 2; i <= n; i++){
            F[i] = F[i - 1] + F[i - 2];
        }
        return F[n] % 1000000007;
    }
};
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了90.39% 的用户
int fib(int n) {
    int a[2] = {0, 1};
    if(n <= 1){
        return a[n];
    }
    bool sw = false;
    for(int i = 2; i < n; i++){
        int res = (a[0] + a[1]) % int(1e9 + 7);
        a[int(sw)] = res;
        sw = !sw;
    }

    return (a[0] + a[1]) % int(1e9 + 7);
}

int main(){
    Solution s;
    cout << s.fib(0) << endl;
    cout << s.fib(1) << endl;
}