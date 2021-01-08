#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了58.49% 的用户
/*
这道题在编程之美上有
每一位上出现1的次数如下：
    (首先跟该位本身本身在哪有关系)
    1.如果该位为0，则次数只跟更高位的数字有关   
    eg.120113中千位出现1的情况为    11000~11999 21000~21999 ... 111000~111999   共12 * 1000个
    2.如果该位为1，则次数跟更高位，更低位的数字都有关
    eg.121113中千位出现1的情况为    即增加了1000~1113 共12000 + 114
    3.该位为其他情况
    eg.122113中千位出现1的情况为    在第一种情况的基础上增加 121000~121999  之后只要高位不变，这一位都不会出现1 共(12 + 1 ) * 1000
*/
int countDigitOne(int n) {
    long long int low;//注意越界问题
    long long int mid;
    long long int high;
    long long int number = 1;
    long long int count = 0;//1的计数
    while(n/number != 0){
        low = n - (n / number) * number;
        mid = (n / number) % 10;
        high = n / (number * 10);
        switch(mid){
            case 0:
            count += high * number;
            break;
            case 1:
            count += high * number + low + 1;
            break;
            default:
            count += (high + 1) * number;
            break;
        }
        number *= 10;
    }
    return count;
}
//下面两种解法没看懂...
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了66.38% 的用户
int countDigitOne(int n) {
    int res = 0;
    for (long k = 1; k <= n; k *= 10) {
        long r = n / k, m = n % k;
        res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
    }
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了59.35% 的用户
int countDigitOne(int n) {
    long res = 0, a = 1, b = 1;
    while (n > 0) {
        res += (n + 8) / 10 * a + (n % 10 == 1) * b;
        b += n % 10 * a;
        a *= 10;
        n /= 10;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}