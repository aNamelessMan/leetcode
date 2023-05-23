//
// Created by 秦俊 on 2023/5/23.
//
#include <unordered_map>

using namespace std;
//贪心算法，算法很简单，但是为什么正确，正确性的证明需要思考下
class Solution {
public:
    static bool comp(const pair<int, int>& l, const pair<int, int>& r){
        return l.first > r.first;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int res = 0;
        int cnt = 0;

        vector<pair<int, int> > p;
        unordered_map<int, int> label_cnt;
        int n = values.size();
        for(int i = 0; i < n; i++){
            p.push_back(pair<int, int>{values[i], labels[i]});
        }
        sort(p.begin(), p.end(), comp);
        for(auto iter = p.begin(); iter != p.end(); iter++){
            if(label_cnt[iter->second] == useLimit){
                continue;
            }
            res += iter->first;
            label_cnt[iter->second]++;
            cnt++;
            if(cnt == numWanted)return res;
        }
        return res;
    }
};

