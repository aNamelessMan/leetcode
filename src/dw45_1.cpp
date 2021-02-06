#include<bits/stdc++.h>
using namespace std;

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> ele;
    int res = 0;
    for(int i: nums){
        ele[i]++;
    }
    for(auto &p:ele){
        if(p.second == 1){
            res += p.first;
        }
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}