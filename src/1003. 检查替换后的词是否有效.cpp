//
// Created by 秦俊 on 2023/5/3.
//

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != 'c')stk.push(s[i]);
            else{
                if(!stk.empty() && stk.top() == 'b'){
                    stk.pop();
                    if(!stk.empty() && stk.top() == 'a'){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main(){
    string str = "aabcbc";
    Solution s;
    s.isValid(str);
}
