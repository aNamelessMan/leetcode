#include <bits/stdc++.h>
using namespace std;

/*
根据题意  第i个游戏的价格实际可认为是bi - (ai - bi) = 2 * bi - ai
01背包dp    快乐值就是想要最大化的价值v，价格就是负重w
dp[i][j]表示在 能看到前i个的物品，有j的负重空间时 所能获得的最大价值
    dp[i][j] = max(
        1.  dp[i - 1][j - wi] + vi  购买第i个物品
        2.  dp[i - 1][j]            不购买第i个物品
        )
    由递推式可知应初始化左上角（第一行）
*/
// 执行用时：64 ms, 在所有 C++ 提交中击败了20.00% 的用户
// 内存消耗：81.5 MB, 在所有 C++ 提交中击败了10.00% 的用户
int main(){
    int n, x;//物品数   预算
    while(cin >> n){
        cin >> x;
        vector<int> w, v;
        long a, b, t, e = 0, pn = n;
        for(int i = 0; i < pn; i++){
            cin >> a >> b >> t;
            int wi = b - (a - b);
            if(wi < 0){//对实际重量小于0的物品特殊处理，一定会购买
                x -= wi;//负重增加
                e += t;//快乐值增加
                n--;//之后不再对这个物品做计算
            }else{
                w.push_back(wi);
                v.push_back(t);
            }
        }
        if(n == 0){
            cout << e << endl;
            break;
        }
        vector<vector<long>> dp(n, vector<long>(x + 1, 0));//艹，因为没用long卡了好久
        for(int j = 0; j <= x; j++){
            if(j >= w[0]){
                dp[0][j] = v[0];
            }else{
                dp[0][j] = 0;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = x; j >= 0; j--){//可以将dp改成一维数组，将下面的横坐标都替换为1即可，但是j就一定要从大到小遍历，时间和空间都会节省很多
            //因为计算当前dp[i][j]只需要dp[i - 1][<j]的值，因此确保在计算当前值时dp[i - 1][<j]的值是有效的即可，也就是j从大到小计算即可
                if(j - w[i] >= 0){
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n - 1][x] + e << endl;
    }
}