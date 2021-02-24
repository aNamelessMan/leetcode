#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.91% 的用户
// 内存消耗：10.8 MB, 在所有 C++ 提交中击败了87.92% 的用户
vector<int> printNumbers(int n) {
    vector<int> res;
    int t = 0;
    while(n){
        t = t * 10 + 9;
        n--;
    }
    while(t){
        res.push_back(t);
        t--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << "print sth." << endl;
}