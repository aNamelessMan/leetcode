#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了7.20% 的用户
//能写成分数的都是有理数，有理数要么是有限的，要么是无限循环小数
string fractionToDecimal(int numerator, int denominator) {
    int s1 = numerator > 0 ? 1 : -1;
    int s2 = denominator > 0 ? 1 : -1;
    long num = abs((long)numerator);
    long den = abs((long)denominator);
    long out = num / den;
    long rem = num % den;
    unordered_map<long, int> m;
    string res = to_string(out);
    if(s1 * s2 == -1 && (out > 0 || rem > 0))res = "-" + res;
    if(rem == 0)return res;
    //以上就已经求出了结果的整数部分
    res += ".";
    string s;
    int pos = 0;
    //m中保存的对的意义为：{计算产生这一位的数, 当前是第几位}
    while(rem){
        if(m.find(rem) != m.end())break;
        m[rem] = pos;
        //注意以上两行在循环中的位置，以及它们的前后顺序
        rem *= 10;
        out = rem / den;
        rem = rem % den;
        pos++;
        s += to_string(out);
    }
    if(rem == 0)return res + s;
    else{
        int b = m[rem];
        s = s.substr(0, b) + "(" + s.substr(b) + ")";
        return res + s;
    }
}

int main(){
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(2, 3) << endl;
    cout << fractionToDecimal(4, 333) << endl;
    cout << fractionToDecimal(1, 5) << endl;
    cout << fractionToDecimal(1, 6) << endl;
}