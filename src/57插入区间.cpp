#include<bits/stdc++.h>
using namespace std;

// 执行用时：40 ms, 在所有 C++ 提交中击败了31.58% 的用户
// 内存消耗：17.4 MB, 在所有 C++ 提交中击败了12.18% 的用户
//困难题，难度不大，就是很难一次考虑全，错了好几次
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = -1, end = -1, n = intervals.size();
    if(!n)return {newInterval};
    vector<vector<int>> res;

    for(int i = 0; i < n; i++){
        if(newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1])start = i;
        if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1])end = i;
    }

    if(start == -1 && end == -1){
        for(int i = 0; i < n; i++){//找第一个起点在newi起点后的
            if(intervals[i][0] > newInterval[0]){
                start = i;
                break;
            }
        }

        if(start == -1){
            intervals.push_back(newInterval);
            return intervals;
        }

        for(int i = n - 1; i >= 0; i--){
            if(intervals[i][1] < newInterval[1]){
                end = i;
                break;
            }
        }

        if(end == -1){
            res.push_back(newInterval);
            for(int i = 0; i < n; i++){
                res.push_back(intervals[i]);
            }
            return res;
        }

        for(int i = 0; i < start; i++){
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        for(int i = end + 1; i < n; i++){
            res.push_back(intervals[i]);
        }
        return res;
    }else if(start != -1 && end != -1){
        if(start == end){
            return intervals;
        }else{
            for(int i = 0; i < start; i++){
                res.push_back(intervals[i]);
            }
            res.push_back({intervals[start][0], intervals[end][1]});
            for(int i = end + 1; i < n; i++){
                    res.push_back(intervals[i]);
            }
            return res;
        }
    }else if(start == -1 && end != -1){
        for(int i = 0; i < end; i++){
            if(intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
        }
        res.push_back({newInterval[0], intervals[end][1]});
        for(int i = end + 1; i < n; i++){
            res.push_back(intervals[i]);
        }
        return res;
    }else{
        for(int i = 0; i < start; i++){
            res.push_back(intervals[i]);
        }
        res.push_back({intervals[start][0], newInterval[1]});
        for(int i = start + 1; i < n; i++){
            if(intervals[i][0] > newInterval[1])
                res.push_back(intervals[i]);
        }
        return res;
    }
}

int main(){
    cout << 1 << endl;
}