#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 97.82% 的提交!
string depress(int m, int k, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int r = 0;
    for(int i = 0; i < k; i++){
        r += arr[i];
    }
    if(r >= m)return "no";
    return "yes";
}

int main(){
    cout << 1 << endl;
}