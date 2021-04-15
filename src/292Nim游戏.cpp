#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了54.30% 的用户
bool canWinNim20210415(int n) {
    /*
    if n <= 3  win
    else dp[n] = !dp[n - 1] || !dp[n - 2] || !dp[n - 3]
    1   2   3   4   5   6   7   8   9   10  11  12  13
    w   w   w   l   w   w   w   l   w   w   w   l   w
    观察可得只有在4的整数被会输
    */
    return n % 4 != 0;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：5.8 MB, 在所有 C++ 提交中击败了96.26% 的用户
//手动推算可得规律如下
//111 0 111 0 111 0 111 ...
//因为每个数本身只需要看跳过前一个后的前5个数中有连续的三个数即为1
bool canWinNim(int n) {
    return !((n % 4) == 0);
}

//显然应该是dp，因为需要倒着推      超时了...
//50 / 60 个通过测试用例    TLE
bool dpcanWinNim(int n) {
    //每人每次至少拿1个，至多拿3个，所以
    //如果我拿1个  那可能下次再拿时会相对减少2-4个    这2-4里必须全为true才会赢
    //如果我拿2个  那可能下次再拿时会相对减少3-5个    这3-5里必须全为true才会赢
    //如果我拿3个  那可能下次再拿时会相对减少4-6个    这4-6里必须全为true才会赢
    //因为我可以选择1-3所以以上三种情况只要一种能赢就可以
    vector<bool> res = {true, true, true, false, true, true};//res[i - 1]是到我的回合时剩余i个的胜负情况
    if(n <= 6)return res[n - 1];
    for(int i = 6; i < n; i++){
        res.push_back((res[i - 2] && res[i - 3] && res[i - 4]) || (res[i - 3] && res[i - 4] && res[i - 5]) || (res[i - 4] && res[i - 5] && res[i - 6]));
        /*
        if(res[i - 2] && res[i - 3] && res[i - 4]){
            res.push_back(true);
            continue;
        }
        if(res[i - 3] && res[i - 4] && res[i - 5]){
            res.push_back(true);
            continue;
        }
        if(res[i - 4] && res[i - 5] && res[i - 6]){
            res.push_back(true);
            continue;
        }
        res.push_back(false);
        */
    }
    return res.back();
}

int main(){
    cout << "print something." << endl;
}