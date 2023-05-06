//
// Created by 秦俊 on 2023/5/6.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<string, int> m;
        int res = 0, t = 0;
        m["c"] = 0;
        m["cr"] = 0;
        m["cro"] = 0;
        m["croa"] = 0;
        for(const auto& ch : croakOfFrogs){
            if(ch == 'c'){
                m["c"] += 1;
                t += 1;
                res = max(res, t);
            }else if(ch == 'r'){
                if(m["c"] == 0){
                    return -1;
                }else{
                    m["c"] -= 1;
                    m["cr"] += 1;
                }
            }else if(ch == 'o'){
                if(m["cr"] == 0){
                    return -1;
                }else{
                    m["cr"] -= 1;
                    m["cro"] += 1;
                }
            }else if(ch == 'a'){
                if(m["cro"] == 0){
                    return -1;
                }else{
                    m["cro"] -= 1;
                    m["croa"] += 1;
                }
            }else{
                if(m["croa"] == 0){
                    return -1;
                }else{
                    m["croa"] -= 1;
                    t -= 1;
                }
            }
        }
        if(m["c"] || m["cr"] || m["cro"] || m["croa"])return -1;
        return res;
    }
};

int main(){
    Solution s;
    cout << s.minNumberOfFrogs("croakcroak") << endl;
}
