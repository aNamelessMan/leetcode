#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了36.82% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了42.28% 的用户
//边界太麻烦了，错了好多次...
string removeKdigits(string num, int k) {
    string res;
    char minn = 58;
    int minidx = 0, n = num.size(), preidx = -1;
    if(k == n)return "0";
    if(k == 0)return num;
    while(k && preidx < n - 1 - k){
        minn = 58;
        for(int i = preidx + 1; i <= preidx + k + 1 && i < n; i++){
            if(num[i] < minn){
                minn = num[i];
                minidx = i;
            }
        }
        if(minn != '0' || !res.empty())
            res += minn;
        k -= (minidx - preidx - 1);
        preidx = minidx;
    }
    for(int i = minidx + 1; i < n - k; i++){
        res += num[i];
    }
    if(res.empty())return "0";
    return res;
}

int main(){
    cout << removeKdigits("1432219", 3) << endl;
    cout << removeKdigits("112", 1) << endl;
    cout << removeKdigits("1173", 2) << endl;
    cout << removeKdigits("1107", 1) << endl;
}