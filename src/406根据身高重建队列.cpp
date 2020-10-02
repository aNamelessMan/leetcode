#include<bits/stdc++.h>
using namespace std;
// 执行用时：272 ms, 在所有 C++ 提交中击败了59.77% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了89.11% 的用户
//按身高由低到高的顺序来考虑
bool isShorter(const vector<int> &p1, const vector<int> &p2){
    return p1[0] < p2[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> res(people.size(), {0, 0});
    sort(people.begin(), people.end(), isShorter);
    vector<bool> Isset(people.size(), false);

    for(unsigned i = 0; i < people.size(); i++){
        int empty = 0;
        unsigned j = 0;
        while(empty < people[i][1]){//预留位置给之后的更大数
            if(!Isset[j] ||res[j][0] == people[i][0])empty++;//注意遇到相等值也要+1
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
    vector<vector<int>> people{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<vector<int>> res = reconstructQueue(people);
    for(unsigned i = 0; i < people.size(); i++){
        cout << res[i][0] << "," << people[i][1] << endl;
    }
}