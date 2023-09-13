// A + B 10^6 + 10^6
// A - B 10^6 + 10^6
// A * a len(A) <= 10^6; a <= 10^9
// A / a

/**
 * 大整数储存，一般存在数组里，且从低位（个位）开始存，比较方便计算
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> div(vector<int>& A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        t = t * 10 + A[i];
        C.push_back(t / b);
        t %= b;
    }
    // 最终余数就是t，需要的话可以传回去

    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    int a_lit = 123123;
    string a = to_string(a_lit);
    int b = 55;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    vector<int> res = div(A, b);
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
    cout << a_lit / b << endl;
}