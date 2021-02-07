#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    vector<int> sts = {a, b, c};
    int res = 0;
    sort(sts.begin(), sts.end());
    while(sts[1] != 0){
        sts[1]--;
        sts[2]--;
        res++;
        sort(sts.begin(), sts.end());
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}