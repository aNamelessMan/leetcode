#include<bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了51.33% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了33.66% 的用户
//只生成丑数
//可以看成是三个有序链表归并
int nthUglyNumber(int n) {
    vector<int> res(1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    n--;
    while(n){
        int m2 = 2 * res[i2], m3 = 3 * res[i3], m5 = 5 * res[i5];
        int mn = min(m2, min(m3, m5));
        if(mn == m2)i2++;
        if(mn == m3)i3++;
        if(mn == m5)i5++;
        res.push_back(mn);
        n--;
    }
    return res.back();
}

//这个解法应该是O(n)，但还是超时了...   418 / 596 个通过测试用例    TLE
//应该是因为丑数在整数中占的很少  第1690个丑数就已经是2123366400了
bool isUgly(int num, unordered_set<int> &uglyno) {
    if(num == 1 || num == 2 || num == 3 || num == 5)return true;
    else if(num / 2 * 2 == num && uglyno.count(num / 2))return true;
    else if(num / 3 * 3 == num && uglyno.count(num / 3))return true;
    else if(num / 5 * 5 == num && uglyno.count(num / 5))return true;
    else return false;
}

int BFnthUglyNumber(int n) {
    unordered_set<int> uglyno;
    int cnt = n;
    int iter = 1;
    while(cnt){
        if(isUgly(iter, uglyno)){
            cnt--;
            uglyno.insert(iter);
        }
        iter++;
    }
    return iter - 1;
}

int main(){
    cout << "print something." << endl;
}