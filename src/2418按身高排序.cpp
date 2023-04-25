//
// Created by 秦俊 on 2023/4/25.
//
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, string> h;
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> res;
        for(int i =0; i < n; i++){
            h[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end());
        for(int i = n - 1; i >= 0; i--){
            res.push_back(h[heights[i]]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> names{"Alice","Bob","Bob"};
    vector<int> heights{155,185,150};
    s.sortPeople(names, heights);
}
