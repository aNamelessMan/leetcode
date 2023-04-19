#include <vector>

using namespace std;

class SolutionBF {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int res = 0;
        if(arr.size() <= k){
            return arr.size() * (*max_element(arr.begin(), arr.end()));
        }
        for(int i = 1; i <= k; i++){
            vector<int> t1 = vector<int>(arr.begin(), arr.begin() + i);
            vector<int> t2 = vector<int>(arr.begin() + i, arr.end());
            res = max(res, i * (*max_element(t1.begin(), t1.end())) + maxSumAfterPartitioning(t2, k));
        }
        return res;
    }
};

class SolutionDP {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        // dp[i]表示arr.sub[0, i]的结果
        for(int i = 1; i < n; i++){
            /** j表示 末尾区间的长度，因此 
             * 1. j = i + 1时表示只有一个区间， 计算结果为 j * max(arr.sub[0, i])
             * 2. 为其他值时，计算结果为 dp[i - j] + j * max(arr.sub[i - j + 1, i])
             * 取其中最大值
             * */
            for(int j = 1; j <= k && j <= i + 1; j++){
                if(j == i + 1){
                    dp[i] = max(dp[i], j * (*max_element(arr.begin() + i + 1 - j, arr.begin() + i + 1)));
                }else{
                    dp[i] = max(dp[i], dp[i - j] + j * (*max_element(arr.begin() + i + 1 - j, arr.begin() + i + 1)));
                }
            }
        }
        return dp[n - 1];
    }
};
