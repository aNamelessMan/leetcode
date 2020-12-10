#include<bits/stdc++.h>
using namespace std;

// 执行用时：40 ms, 在所有 C++ 提交中击败了86.52% 的用户
// 内存消耗：17.1 MB, 在所有 C++ 提交中击败了22.35% 的用户
int candy(vector<int>& ratings) {
    int n = ratings.size();
    if(n == 0)return 0;
    if(n == 1)return 1;
    vector<int> cd(n, 1);
    for(int i = 0; i < n - 1; i++){
        if(ratings[i] < ratings[i + 1])cd[i + 1] = cd[i] + 1;
    }
    for(int i = n - 1; i >= 1; i--){
        if(ratings[i] < ratings[i - 1] && cd[i] >= cd[i - 1])cd[i - 1] = cd[i] + 1;
    }
    int res = 0;
    for(int c:cd)res += c;
    return res;
}

int main(){
    cout << 1 << endl;
}