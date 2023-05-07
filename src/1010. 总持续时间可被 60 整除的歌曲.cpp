//
// Created by 秦俊 on 2023/5/7.
//
#include <vector>

using namespace std;

class BFSolution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((time[i] + time[j]) % 60 == 0){
                    res++;
                }
            }
        }
        return res;
    }
};
// We only need to consider each song length modulo 60.
// We can count the number of songs with (length % 60) equal to r, and store that in an array of size 60.
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), res = 0;
        vector<int> mod(60, 0);
        for(const auto& t : time){
            mod[t % 60]++;
        }
        res += (mod[0] * (mod[0] - 1L)) / 2L;
        res += (mod[30] * (mod[30] - 1L)) / 2L;
        for(int i = 1; i < 30; i++){
            res += mod[i] * mod[60 - i];
        }
        return res;
    }
};
