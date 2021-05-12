#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了68.28% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了90.80% 的用户
// 21.5.12二刷，做法和以前一样
string intToRoman(int n, string one, string five, string ten){
    string res;
    if(n == 0){}
    else if(n == 9){
        res = one + ten;
    }
    else if(n <= 3){
        while(n){
            res += one;
            n--;
        }
    }else if(n == 4){
        res = one + five;
    }else{
        res = five;
        n -= 5;
        while(n){
            res += one;
            n--;
        }
    }
    return res;
}

string intToRoman(int num) {
    string res;
    res += intToRoman(num / 1000 % 10, "M", " ", " ");
    res += intToRoman(num / 100 % 10, "C", "D", "M");
    res += intToRoman(num / 10 % 10, "X", "L", "C");
    res += intToRoman(num / 1 % 10, "I", "V", "X");
    return res;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.20% 的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了99.97% 的用户
void calc(string &res, char t, char f, char o, int num){
    if(!num)return;
    if(num < 4){
        for(int i = 0; i < num; i++)res += o;
    }else if(num == 4){
        res += o; res += f;
    }else if(num < 9){
        res += f;
        for(int i = 0; i < num - 5; i++)res += o;
    }else{
        res += o; res += t;
    }
}
//暴力解法，没有难度，感觉这题应该算简单，但显示的中等
string intToRoman(int num) {
    string res;

    int k = num / 1000;
    for(int i = 0; i < k; i++){
        res += 'M';
    }
    num %= 1000;
    int h = num / 100;
    calc(res, 'M', 'D', 'C', h);
    num %= 100;
    int t = num / 10;
    calc(res, 'C', 'L', 'X', t);
    num %= 10;
    calc(res, 'X', 'V', 'I', num);
    return res;
}

int main(){
    cout << intToRoman(3) << endl;
    cout << intToRoman(4) << endl;
    cout << intToRoman(9) << endl;
    cout << intToRoman(58) << endl;
    cout << intToRoman(1994) << endl;
}