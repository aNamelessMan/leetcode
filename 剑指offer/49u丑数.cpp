#include <bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了59.77% 的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了23.56% 的用户
int nthUglyNumber(int n) {
    vector<int> res;
    res.push_back(1);
    int i2 = 0, i3 = 0, i5 = 0;
    n--;
    while(n){
        int n2 = 2 * res[i2], n3 = 3 * res[i3], n5 = 5 * res[i5];
        int nmn = min({n2, n3, n5});
        res.push_back(nmn);
        if(nmn == n2)i2++;//注意此处不可改成if elseif else否则会导致重复值被放入res
        if(nmn == n3)i3++;
        if(nmn == n5)i5++;
        n--;
    }
    return res.back();
}

int main(){
    nthUglyNumber(10);
    cout << "print sth." << endl;
}