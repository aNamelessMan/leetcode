#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 19.33% 的提交!
int getSum(int A, int B) {
    int res = 0;
    for(int i = A; i <= B; i++){
        if(i % 3 == 0)res += i;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}