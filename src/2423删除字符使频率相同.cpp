//
// Created by 秦俊 on 2023/5/3.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // corner case太多了！！！
    bool equalFrequency(string word) {
        unordered_map<char, int> cnt;
        unordered_map<int, int> f;
        for(const auto& ch : word){
            cnt[ch]++;
        }
        if(cnt.size() == 1)return true;
        for(const auto& p : cnt){
            f[p.second]++;
        }
        if(f.size() == 1 && (f.begin())->first == 1)return true;
        if(f.size() != 2)return false;
        auto iter = f.begin();
        auto fst = *iter;
        iter++;
        auto snd = *iter;
        if(fst.first == 1 && fst.second == 1 || snd.first == 1 && snd.second == 1)return true;
        if((fst.second == 1) && fst.first == snd.first + 1 || (snd.second == 1 && snd.first == fst.first + 1))return true;
        return false;
    }
};