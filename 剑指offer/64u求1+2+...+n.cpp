#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了55.36% 的用户
typedef int (*fun)(int);//定义fun为int (int)类型的函数指针
static int over(int r){//在类定义中必须加static 因为指代非静态成员函数指针很特殊，因为要根据对象来调用
    return 0;
}
static int sumNums(int n) {
    fun sz[2] = {over, sumNums};
    return n + sz[!!(n - 1)](n - 1);//实际上就是用!!(n-1)判断是否为0终止
}

int main(){
    cout << "print sth." << endl;
}