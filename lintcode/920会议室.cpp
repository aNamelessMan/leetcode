#include<bits/stdc++.h>
#include "Interval.hpp"
using namespace std;

//您的提交打败了 22.40% 的提交!

bool com(const Interval& i1,const Interval& i2){
    return i1.start < i2.start;
}
bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), com);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i - 1].end > intervals[i].start)return false;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}