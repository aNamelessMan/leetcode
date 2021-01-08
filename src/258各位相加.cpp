#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了51.36% 的用户
//观察可知  结果就是该数对9取余，除了9对自身取余是0，但我们想要的是9，为了处理这种情况转换为(num - 1) % 9 + 1
int addDigits(int num) {
    return (num - 1) % 9 + 1;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了49.37% 的用户
int addDigits(int num) {
    while(num > 9){
        int cnt = 0;
        while(num){
            cnt += (num % 10);
            num /= 10;
        }
        num = cnt;
    }
    return num;
}

int main(){
    cout << 1 << endl;
}