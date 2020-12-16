#include<bits/stdc++.h>
using namespace std;

//思路是正确的，但是res一开始定义成了int，应该定义成long
//但是lintcode周赛不显示哪里错了，结果就卡住了...
//不显示错误的测例，确定思路没问题，可以看看是不是有数据会溢出...
long long arrayGame(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int min = arr[0], n = arr.size();
    long res = 0;
    for(int i = 0; i < n; i++){
        res += (arr[i] - min);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}