//
// Created by 秦俊 on 2023/5/9.
//
#include <string>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int hr = 0, min = 0;
        if(time[0] == '?'){
            if(time[1] == '?'){
                hr = 24;
            }else if(time[1] >= '4'){
                hr = 2;
            }else{
                hr = 3;
            }
        }else{
            if(time[1] == '?'){
                if(time[0] == '0' || time[0] == '1'){
                    hr = 10;
                }else{
                    hr = 4;
                }
            }else{
                hr = 1;
            }
        }
        if(time[3] == '?'){
            if(time[4] == '?'){
                min = 60;
            }else{
                min = 6;
            }
        }else{
            if(time[4] == '?'){
                min = 10;
            }else{
                min = 1;
            }
        }
        return hr * min;
    }
};
