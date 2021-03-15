#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了73.46% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了54.60% 的用户
//3.15日    官方的解法，比较清晰
int myAtoi(string s) {
    int i = 0, n = s.size(), res = 0;
    while(i < n && s[i] == ' ')i++;
    if(i == n)return res;
    bool sign = true;
    if(s[i] == '+')i++;
    else if(s[i] == '-'){
        sign = false;
        i++;
    }
    while(i < n && s[i] >= '0' && s[i] <= '9'){
        int r = s[i] - '0';
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)){//只有这两种情况会溢出
            return sign?INT_MAX:INT_MIN;
        }
        res = 10 * res + r;
        i++;
    }
    return sign?res:-res;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了81.19% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了95.43% 的用户
//时间波动
//思路很简单，还是注意边界条件和认真读题
//1.溢出不是返回0而是返回上下限
//2.符号也可能是+
//3.空格的ascii码不是0，应该用' '，不要想当然
int myAtoi(string str) {
    int i = 0;
    while(str[i] == ' '){
        i++;
    }

    if(str[i] != '-' && str[i] != '+' && (str[i] > '9' || str[i] < '0')){
        return 0;
    }

    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }else if(str[i] == '+')i++;
    long res = 0;
    while(str[i] <= '9' && str[i] >= '0' && i < str.size()){
        res = 10*res + str[i] - '0';
        i++;
        if(res > (long)INT_MAX + 1)break;
    }
    res = sign * res;
    if(res < INT_MIN)return INT_MIN;
    else if(res > INT_MAX)return INT_MAX;
    return res;
}

int main(){
    cout << myAtoi("20000000000000000000") << endl;
}