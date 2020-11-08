#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 5.20% 的提交!
//选择排序  O(n^2)
void sortIntegers(vector<int> &A) {
    if(A.size() < 2)return;
    for(int i = 0; i < A.size(); i++){
        int m = A[i];
        int minidx = i;
        for(int j = i + 1; j < A.size(); j++){
            if(A[j] < m){
                m = A[j];
                minidx = j;
            }
        }
        int t = A[i];
        A[i] = A[minidx];
        A[minidx] = t;
    }
}

int main(){
    cout << 1 << endl;
}