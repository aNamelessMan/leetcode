#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.6 MB, 在所有 C++ 提交中击败了99.01% 的用户
int add(int a, int b) {
    bool f = true;
    int carry = 0;
    while(f || carry){
        int sum = a ^ b;//只计算和不考虑进位
        carry = unsigned(a & b) << 1;//进位值   先转为无符号移位后再转为int
        a = sum;
        b = carry;
        f = false;
    }
    return a;
}

int main(){
    cout << "print sth." << endl;
}