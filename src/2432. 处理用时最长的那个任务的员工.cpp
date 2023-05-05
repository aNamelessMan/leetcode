//
// Created by 秦俊 on 2023/5/5.
//
#include <vector>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = logs[0][1], id = logs[0][0], no = logs.size();
        for(int i = 1; i < no; i++){
            int t = logs[i][1] - logs[i - 1][1];
            if(t > res){
                res = t;
                id = logs[i][0];
            }else if(t == res){
                id = min(id, logs[i][0]);
            }
        }
        return id;
    }
};
