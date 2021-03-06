#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> d;
    for(int i = 1; i < n; i++){
        d.push_back(A[i] - A[i - 1]);
    }
    //长度为n的等差数列包含(n - 1) * n / 2 个区间
    vector<int> a;
    int cur = d[0], cnt = 1;
    for(int i = 1; i < d.size(); i++){
        if(d[i] == cur)cnt++;
        else{
            a.push_back(cnt);
            cur = d[i];
            cnt = 1;
        }
    }
    a.push_back(cnt);
    int res = 0;
    for(int i:a){
        res += (i - 1) * i / 2;
    }
    return res;
}

int main(){
    vector<int> nums{-1, 1, 3,3,3,2,3,2,1,0};
    solution(nums);
    cout << "print sth." << endl;
}