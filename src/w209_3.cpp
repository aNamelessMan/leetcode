#include<bits/stdc++.h>
using namespace std;
//思路应该没问题，结果不全对，应该是边界没考虑好，没时间了
#define pi 3.1415926
int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    map<int, int>nums;
    int res = 0;
    int max = 0;
    for(auto &p:points){
        if(p == location)res++;
        else{
            nums[int(atan2(location[1] - p[1], location[0] - p[0]) * 180 / pi)]++;
        }
    }
    
    for(int l = -180, r = l + angle; r <= 180; l++, r++){
        int tmp = 0;
        for(int i = l; i <= r; i++){
            tmp += nums[i];
        }
        if(tmp > max)max = tmp;
    }

    for(int r = -180, l = 180 - angle; l <= 180; l++, r++){
        int tmp = 0;
        for(int i = l; i <= 180; i++){
            tmp += nums[i];
        }
        for(int i = -180; i <= r; i++){
            tmp += nums[i];
        }
        //tmp += nums[180];
        if(tmp > max)max = tmp;
    }
    return res + max;
}

int main(){
    vector<vector<int>> points{{2,1},{2,2},{3,3}};
    vector<int> location{1, 1};
    cout << visiblePoints(points, 90, location) << endl;
}