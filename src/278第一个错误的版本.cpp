#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了93.68% 的用户
bool isBadVersion(int c){
    return true;
}
int firstBadVersion(int n) {
    int l = 1, h = n;
    while(l < h){
        int mid = l + (h - l) / 2;
        if(isBadVersion(mid)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }//出循环时l一定大于h
    return l;
}

int main(){
    cout << "print something." << endl;
}