#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了12.70% 的用户
int bs(int lb, int hb, int target){
    if(lb > hb)return -1;
    int mid = (lb + hb) / 2;
    if(mid == target / mid)return mid;
    if(hb - lb == 1)return lb;
    else if(mid < target / mid)return bs(mid, hb, target);
    else return bs(lb, mid, target);
}
int mySqrt(int x) {
    if(x <= 1)return x;
    return bs(0, x, x);
}

int main(){
    cout << 1 << endl;
}