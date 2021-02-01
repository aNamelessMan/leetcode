#include <bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：3.3 MB, 在所有 C++ 提交中击败了100.00% 的用户
int main(){//元素名称可能是多个字符
    string input;
    while(cin >> input){
        map<string, int> cnt;
        int cur = 1;
        vector<int> fac;
        int i = 0, n = input.size();
        while(i < n){
            if(input[i] == '['){
                int no = 1;
                int j = i + 1;//要找跟他匹配的括号，因为可能会有嵌套eg. z[a[bc]2]3
                while(no != 0 && j < n){
                    if(input[j] == ']')no--;
                    if(input[j] == '[')no++;
                    j++;
                }
                if(j < n){
                    fac.push_back(input[j] - '0');
                    cur *= input[j] - '0';
                }else{//括号后有可能没有数字
                    fac.push_back(1);
                }
            }else if(input[i] == '('){
                int no = 1;
                int j = i + 1;//要找跟他匹配的括号，因为可能会有嵌套
                while(no != 0 && j < n){
                    if(input[j] == ')')no--;
                    if(input[j] == '(')no++;
                    j++;
                }
                if(j < n){
                    fac.push_back(input[j] - '0');
                    cur *= input[j] - '0';
                }else{
                    fac.push_back(1);
                }
            }else if(input[i] == ']'){
                cur /= fac.back();
                fac.pop_back();
            }else if(input[i] == ')'){
                cur /= fac.back();
                fac.pop_back();
            }else if(input[i] > '0' && input[i] <= '9'){

            }else{//元素
                string ele;
                char c = input[i];
                if(i + 1 < n && input[i + 1] >= 'a' && input[i + 1] <= 'z'){//小写字符则是名称一部分
                    ele = input.substr(i, 2);
                    i++;
                }else{
                    ele = input.substr(i, 1);
                }
                if(i + 1 < n && input[i + 1] > '0' && input[i + 1] <= '9'){
                    cnt[ele] += (input[i + 1] - '0') * cur;
                    i++;
                }else{
                    cnt[ele] += cur;
                }
            }
            i++;
        }
        for(auto &p:cnt){
            cout << p.first << p.second;
        }
        cout << endl;
    }
}