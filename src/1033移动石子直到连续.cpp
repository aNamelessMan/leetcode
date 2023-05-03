//
// Created by 秦俊 on 2023/5/3.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr = vector<int>{a, b, c};
        sort(arr.begin(), arr.end());
        a = arr[0]; b = arr[1]; c = arr[2];
        int mn1 = min(b - a - 1, 1), mx1 = b - a - 1;
        int mn2 = min(c - b - 1, 1), mx2 = c - b - 1;
        // corner case
        if(a + 2 == b || b + 2 == c) return {1, mx1 + mx2};
        return vector<int>{mn1 + mn2, mx1 + mx2};
    }
};
