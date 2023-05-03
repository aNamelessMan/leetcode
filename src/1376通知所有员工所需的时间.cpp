//
// Created by 秦俊 on 2023/5/3.
//

#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(int& res, const int curID, int curW, unordered_map<int, unordered_set<int>> &tree, const vector<int>& informTime){
        if(tree[curID].empty()){
            res = max(res, curW);
        }else{
            for(const auto& id : tree[curID]){
                curW += informTime[curID];
                dfs(res, id, curW, tree, informTime);
                // 记得回退！！！
                curW -= informTime[curID];
            }
        }
        return;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        unordered_map<int, unordered_set<int>> tree;
        for(int i = 0; i < n; i++){
            if(manager[i] == -1)continue;
            tree[manager[i]].insert(i);
        }
        dfs(res, headID, 0, tree, informTime);
        return res;
    }
};
