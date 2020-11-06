#include<bits/stdc++.h>
using namespace std;
// 执行用时：28 ms, 在所有 C++ 提交中击败了31.20% 的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了29.69% 的用户
int countOne(int i){
    int res = 0;
    while(i){
        if(i % 2)res++;
        i /= 2;
    }
    return res;
}
bool compare(const int &i1, const int &i2){
    int c1 = countOne(i1), c2 = countOne(i2);
    if(c1 == c2)return i1 < i2;
    else return c1 < c2;
}
vector<int> sortByBits(vector<int>& arr) {
    if(arr.size() < 2)return arr;
    sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main(){
    cout << 1 << endl;
}