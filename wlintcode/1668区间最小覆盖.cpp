#include<bits/stdc++.h>
#include "Interval.hpp"
using namespace std;

// 数轴上有 n 个区间. 现在需要在数轴上选取一些点, 使得任意一个区间内至少包含一个点.
// 返回最少选取的点的数目.
//排序加贪心
bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}
int getAns(vector<Interval> &a) {
    sort(a.begin(), a.end(), compare);
    int res = 1;
    Interval t = a[0];
    int n = a.size();
    for(int i = 1; i < n; i++){
        if(t.end >= a[i].start){
            t.start = a[i].start;
            t.end = min(t.end, a[i].end);
        }
        else{
            t.start = a[i].start;
            t.end = a[i].end;
            res++;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}