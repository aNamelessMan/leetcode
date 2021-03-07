#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了59.61% 的用户
int countDigitOne(int n) {
    long h1 = 1, h2 = 10;//辅助变量
    int res = 0;
    while(n / h1){
        int back = n % h1;//此位之后的数字
        int front = n - n % h2;//此位之前的数字
        int cur = n - front - back;
        cur /= h1;
        h1 *= 10;
        h2 *= 10;

        if(cur == 0){//如果此位为0，则此位出现1的次数与前后都有关系
            res += front / 10;
        }else if(cur == 1){
            res += front / 10 + back + 1;
        }else{
            res += front / 10 + h1 / 10;
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}