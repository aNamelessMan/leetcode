#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 100.00% 的提交!
//想考察的应该是二分...
vector<int> searchRange(vector<int> &A, int target) {
    int start = -1, end = -1, n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] == target){
            start = i;
            end = n - 1;
            break;
        }
    }
    for(int i = start + 1; i < n; i++){
        if(A[i] != target){
            end = i - 1;
            break;
        }
    }
    return {start,end};
}

int main(){
    cout << 1 << endl;
}