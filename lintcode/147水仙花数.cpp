#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 32.40% 的提交!
bool isn(int num, int n){
    int r = 0, numcopy = num;
    while(num){
        int t = num % 10;
        num /= 10;
        r += pow(t, n);
    }
    return (r == numcopy);
}
vector<int> getNarcissisticNumbers(int n) {
    vector<int> res;
    int s;
    if(n == 1) s = 0;
    else s = pow(10, n - 1);
    int e = pow(10, n);
    for(int i = s; i < e; i++){
        if(isn(i, n))res.push_back(i);
    }
    return res;
}

int main(){
    vector<int> res = getNarcissisticNumbers(2);
    for(auto &i:res)cout << i << endl;
}