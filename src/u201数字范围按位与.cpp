#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了96.78% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了40.97% 的用户
int rangeBitwiseAnd(int m, int n) {
    unsigned int d = INT_MAX;
    while ((m & d) != (n & d)) {//最后结果是m和n的从左往右的最长公共部分，剩下的补0
        d <<= 1;
    }
    return m & d;
}

// 8256 / 8266 个通过测试用例   TLE
int BFrangeBitwiseAnd(int m, int n) {
    //2147483647 是 2^31 - 1 因此只需判断2^0到2^30是否为1即可
    //记录每一位为1的个数
    vector<int> res(31, 0);
    for(int i = m; i <= n; i++){
        int t = i;
        for(int j = 2, cnt = 0; cnt < 31; cnt++){
            if(t % j)res[cnt]++;
            t /= 2;
        }
    }
    long c = 1, ans = 0;
    for(int i = 0; i < 31; i++){
        if(res[i] == n - m + 1)ans += c;
        c *= 2;
    }
    return ans;
}

int main(){
    cout << rangeBitwiseAnd(5, 7) << endl;
}