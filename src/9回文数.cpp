// 执行用时：12 ms, 在所有 C++ 提交中击败了83.07% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了52.06% 的用户
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        else{
            string strx = to_string(x);
            for(int i = 0,j = strx.size() - 1; i <= j; i++, j--){
                if(strx[i] != strx[j])return false;
            }
            return true;
        }
    }
};