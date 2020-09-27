#include<bits/stdc++.h>
using namespace std;
// 执行用时：16 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
int minOperations(vector<string>& logs) {
    int res = 0;
    for(auto &str:logs){
        if(str == "./");
        else if(str == "../"){
            if(res > 0)
                res--;
        }
        else res++;
    } 
    if(res < 0)return 0;
        return res;
}

int main(){
    cout << 1 << endl;
}