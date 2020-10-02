#include<bits/stdc++.h>
using namespace std;

bool isShorter(const vector<int> &p1, const vector<int> &p2){
    return p1[0] < p2[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> res(people.size(), {0, 0});
    sort(people.begin(), people.end(), isShorter);
    vector<bool> Isset(people.size(), false);

    for(unsigned i = 0; i < people.size(); i++){
        int empty = 0, j = 0;
        while(empty < people[i][1] && j < people.size()){//预留位置给之后的更大数
            if(!Isset[j])empty++;
            j++;
        }

        while(Isset[j]){
            j++;
        }
        Isset[j] = true;
        res[j] = people[i];
    }
    return res;
}

int main(){
    cout << 1 << endl;
}