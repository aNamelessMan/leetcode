#include <bits/stdc++.h>

using namespace std;

/**
 * 需要保证入参 A >= B，要保证这点其实很简单，如果 B > A，就调换，加个负号即可
 * 比较大小：
 * 1. 先比较位数
 * 2. 位数相同则从高位开始比
 * */
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) {
            t = t - B[i];
        }
        C.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }
    // 因为 A 必定大于等于 B，所以最后不会有借位，不用判断t是否为0
    // 去除可能存在的前导零
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a = "675675";
    string b = "675675";
    // string b = "123123";

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    vector<int> res = sub(A, B);
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}