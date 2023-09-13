// A + B 10^6 + 10^6
// A - B 10^6 + 10^6
// A * a len(A) <= 10^6; a <= 10^9
// A / a

/**
 * 大整数储存，一般存在数组里，且从低位（个位）开始存，比较方便计算
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    // 记得处理最后的进位
    if (t != 0) C.push_back(t);
    return C;
}

int main() {
    string a = "123123";
    string b = "675675";

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    vector<int> res = add(A, B);
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}