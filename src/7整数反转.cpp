#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了65.81% 的用户
//21.5.10二刷，比之前写的更简洁
int reverse(int x) {
    if(x == INT_MIN)return 0;
    bool sign = x >= 0;
    x = abs(x);
    int res = 0;
    while(x){
        int t = x % 10;
        x /= 10;
        if((sign && (res > 214748364) || (res == 214748364 && t > 7)) || (!sign && ((res > 214748364) || (res == 214748364 && t > 8)))){
            return 0;
        }
        res = res * 10 + t;
    }
    return sign?res:-res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了5.05% 的用户
//执行用时有波动，有时是4ms，击败50%
//思路很简单，主要是注意溢出，判题的编译器一旦溢出就报错，其次是正负转换时区间并不对称不能简单的乘-1
int reverse_pos(int x){
    queue<int> num;
    while(x){
        num.push(x % 10);
        x /= 10;
    }
    //tmp的作用就是检出溢出
    long tmp = 0;
    int res = 0;
    while(!num.empty()){
        tmp = 10*tmp + num.front();
        if(tmp > 2147483647){
            return 0;
        }
        res = tmp;
        num.pop();
    }
    return res;
}

int reverse(int x) {
    if(x == -2147483648)return 0;
    if(x < 0){
        x *= -1;
        return -1 * reverse_pos(x);
    }
    else if(x > 0){
        return reverse_pos(x);
    }
    else{return 0;}
}

int main(){
    cout << reverse(-2147483648) << endl;
}