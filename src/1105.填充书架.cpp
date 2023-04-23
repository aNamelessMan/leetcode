class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        size_t n = books.size();
        vector<int> dp(n + 1, 1000 * 1000);
        dp[0] = 0;
        /** 动态规划
         * dp[i]表示加入i本书后的最小高度，迭代i计算的是加入i+1本书后的结果
         * j表示最后一层的书本数 - 1，因此最后一层高度取决于最高的那本书，最后一层书的本数j一定小于i，厚度和小于shelfWidth
         * 遍历最后一层放的书本数的所有情况，选其中的最小值（最后一层从逻辑上讲一定至少有一本书））
         * */
        for(size_t i = 0; i < n; i++){
            int curWidth = 0;
            int maxH = 0;
            for(int j = 0; j <= i; j++){
                curWidth += books[i - j][0];
                maxH = max(maxH, books[i - j][1]);
                if(curWidth >shelfWidth)break;
                dp[i + 1] = min(dp[i + 1], dp[i - j] + maxH);
            }
        }
        return dp[n];
    }
};