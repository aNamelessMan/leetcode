#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了78.16% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了54.24% 的用户
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F);

    int left = max(A, E), right = max(left, min(C, G));//求重叠区域的左右边的横坐标，无重叠时l == r
    int bot = max(B, F), top = max(bot, min(D, H));

    return s1 - (right - left) * (top - bot) + s2;
}

int main(){
    cout << 1 << endl;
}