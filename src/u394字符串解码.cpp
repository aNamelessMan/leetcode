#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了62.47% 的用户
string decode(string s, unsigned &i){
    string res = "";
    while(s[i] != ']' && i < s.size()){

        if(s[i] > '0' && s[i] <= '9'){//有数字和[]的情况
            int num = 0;
            //除了首字符其余数字可以为'0'因此有等号
            while(s[i] >= '0' && s[i] <= '9'){
                num = 10 * num + s[i] - '0';
                i++;
            }

            i++;//数字后的第一个字符一定是'['，跳过
            string tmp = decode(s, i);//注意对[]内的字符需要递归处理
            i++; //跳过']'

            for(int i = 0; i < num; i++){
                res += tmp;
            }

        }else{//普通情况
            res += s[i];
            i++;
        }      

    }
    return res;
}

string decodeString(string s) {
    //这题显然要用栈或递归
    unsigned i = 0;
    return decode(s, i);
}

int main(){
    cout << decodeString("100[leetcode]") << endl;
}