//
// Created by 秦俊 on 2023/5/4.
//
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
//    本地跑是对的，但力扣过不了，暂且放弃
    int maxTotalFruits(vector<vector<int> >& fruits, int startPos, int k) {
        int res = 0, n = fruits.size();
        map<int, int> prefixSum;
        for(int i = 0; i < n; i++){
            prefixSum[fruits[i][0]] = fruits[i][1];
        }
        if(k == 0){
            return prefixSum.find(startPos) == prefixSum.end() ? 0 : prefixSum[startPos];
        }
        auto iter = prefixSum.begin();
        for(int i = 0; i < n - 1; i++){
            auto preiter = iter;
            iter++;
            iter->second += preiter->second;
        }

        for(int l = 0; l <= k; l++){
            int r = k - 2 * l;
            int lBound = startPos - l;
            int rBound = startPos + r;
            auto rb = prefixSum.upper_bound(rBound);
            auto lb = prefixSum.lower_bound(lBound);
            if(rb == prefixSum.end() || rb->first > rBound){
                if(rb != prefixSum.begin()){
                    rb--;
                }else{
                    res = max(res, 0);
                    continue;
                }
            }
            if(lb->first >= lBound){
                if(lb != prefixSum.begin()){
                    lb--;
                }else{
                    res = max(res, rb->second);
                    continue;
                }
            }
            res = max(res, rb->second - lb->second);
        }
        for(int r = 0; r <= k; r++){
            int l = k - 2 * r;
            int lBound = startPos - l;
            int rBound = startPos + r;
            auto rb = prefixSum.upper_bound(rBound);
            auto lb = prefixSum.lower_bound(lBound);
            if(rb == prefixSum.end() || rb->first > rBound){
                if(rb != prefixSum.begin()){
                    rb--;
                }else{
                    res = max(res, 0);
                    continue;
                }
            }
            if(lb->first >= lBound){
                if(lb != prefixSum.begin()){
                    lb--;
                }else{
                    res = max(res, rb->second);
                    continue;
                }
            }
            res = max(res, rb->second - lb->second);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> fruits{{2, 8}, { 6, 3 }, { 8, 6 }};
    Solution s;
    cout << s.maxTotalFruits(fruits, 5, 4) << endl;
}

