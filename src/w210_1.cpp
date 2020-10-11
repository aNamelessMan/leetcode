#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int t = 0;
    int max = 0;
    stack<int> stk;
    for(auto &c:s){
        if(c == '('){
            t++;
            if(t > max)max = t; 
        }else if(c == ')')t--;
    }
    return max;
}

int main(){
    cout << 1 << endl;
}