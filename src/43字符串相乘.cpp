#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了58.52% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了52.83% 的用户
//没什么难度但是比较麻烦，花了很长时间
string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    if(num1 == "0" || num2 == "0")return "0";
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    string res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int n2 = num2[i] - '0', n1 = num1[j] - '0', s = res.size();
            int t;
            if(i + j > s - 1) {
                t = n2 * n1;
                if(t <= 9){
                    res.push_back(t + '0');
                }else{
                    res.push_back(t % 10 + '0');
                    res.push_back(t / 10 + '0');
                }
            }
            else{
                t = n2 * n1 + res[i + j] - '0';
                int carry = t / 10, cur = i + j;
                res[i + j] = t % 10 + '0';
                while(carry){//i + j <= s - 1不能直接直接res.push_back(carry)
                    cur++;
                    if(cur > (int)res.size() - 1){
                        res.push_back(carry + '0');
                        carry = 0;
                    }else{
                        t = carry + res[cur] - '0';
                        carry = t / 10;
                        res[cur] = t % 10 + '0';
                    }
                }
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout << multiply("123", "456") << endl;
}