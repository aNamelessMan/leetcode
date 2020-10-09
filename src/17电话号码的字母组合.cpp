#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了12.12% 的用户   第一次提交波动比较大

// 执行用时：4 ms, 在所有 C++ 提交中击败了49.75% 的用户     稳定后大概是这样
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了59.16% 的用户
map<int, vector<char>> table;
vector<string> res;
string tmp;
void traverseNum(string s, int n){
    if(n == (int)s.size())res.push_back(tmp);
    else{
        if(n == 0)tmp = "";
        for(auto &c:table[s[n] - '0']){
            tmp += c;
            traverseNum(s, n + 1);
            tmp.pop_back();//注意这行不要忘了
        }
    }
}
vector<string> letterCombinations(string digits) {
    if(digits.empty())return {};
    table[2] = {'a', 'b', 'c'};
    table[3] = {'d', 'e', 'f'};
    table[4] = {'g', 'h', 'i'};
    table[5] = {'j', 'k', 'l'};
    table[6] = {'m', 'n', 'o'};
    table[7] = {'p', 'q', 'r', 's'};
    table[8] = {'t', 'u', 'v'};
    table[9] = {'w', 'x', 'y', 'z'};
    traverseNum(digits, 0);
    return res;
}

int main(){
    letterCombinations("23");
}