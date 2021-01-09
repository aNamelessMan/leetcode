#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.9 MB, 在所有 C++ 提交中击败了83.13% 的用户
//num的范围是[−2^31,  2^31 − 1]   所以注意判断0，不然会无限递归
bool isUgly(int num) {
    if(num == 1)return true;
    else if(num == 0)return false;
    else if(num / 2 * 2 == num)return isUgly(num / 2);
    else if(num / 3 * 3 == num)return isUgly(num / 3);
    else if(num / 5 * 5 == num)return isUgly(num / 5);
    else return false;
}
int main(){
    cout << "print something." << endl;
}