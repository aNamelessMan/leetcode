#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 22.40% 的提交!
class Interval {
    public:
    int start, end;
    Interval(int start, int end) {
       this->start = start;
       this->end = end;
    }
};

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