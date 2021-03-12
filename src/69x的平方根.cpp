#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了59.46% 的用户
//2021.3.12日二刷
int mySqrt(int x) {
    int l = 0, r = x;
    while(l < r){
        long mid = (l + r) / 2;
        if(mid * mid <= x && (mid + 1) * (mid + 1) > x)return mid;
        else if(mid * mid <= x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;//返回l还是r就是考虑当r = l + 1时，r为正确结果/l为正确结果两种情况 看看返回谁才正确    这里l为正确值时会在循环内部就返回，只有r为结果时才需要到外面来返回
}

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
int fstmySqrt(int x) {
    if(x <= 1)return x;
    return bs(0, x, x);
}

int main(){
    cout << 1 << endl;
}