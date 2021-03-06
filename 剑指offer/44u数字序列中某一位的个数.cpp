#include <bits/stdc++.h>
using namespace std;

int findNthDigit(int n) {
    if(n == 0)return 0;
    n--;//n表示剩余位数 这样当n为0时表示数字就是start
    long cnt = 9;//位数为1的数字的个数
    long bits = 1;//当前占有位数为1
    long start = 1;//起始数字
    while(n > cnt * bits){
        n -= cnt * bits;
        start += cnt;
        cnt *= 10;
        bits++;
    }
    long num = start + (n / bits);
    string s = to_string(num);
    return s[n % bits] - '0';
}

int main(){
    cout << "print sth." << endl;
}