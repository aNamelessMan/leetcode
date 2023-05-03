//
// Created by 秦俊 on 2023/5/3.
//

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        for(int i = 0; 1; i++){
            for(int j = 0; 1; j++){
                int t = pow(x, i) + pow(y, j);
                if(t > bound)break;
                else{
                    res.insert(t);
                }
                if(y == 1)break;
            }
            // 注意corner case!!! x == 1 || y == 1
            if(pow(x, i) + 1 > bound || x == 1)break;
        }
        return vector<int>(res.begin(), res.end());
    }
};
