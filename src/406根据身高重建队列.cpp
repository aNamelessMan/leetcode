#include<bits/stdc++.h>
using namespace std;

// 执行用时：160 ms, 在所有 C++ 提交中击败了64.61% 的用户
// 内存消耗：10.8 MB, 在所有 C++ 提交中击败了93.64% 的用户
//20.11.16号每日一题重刷了一遍，相比之前改进了下排序函数
//身高相同时按照第二个参数由大到小排，可以确保遍历时在遇到相同数之前就结束，等于是第一个相同值遍历时已经为其余相同值预留了位置
bool compare(const vector<int> &v1, const vector<int> &v2){
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
    else
        return v1[0] < v2[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    int n = people.size();
    if(n == 0)return {};
    vector<vector<int>> res(n);
    vector<bool> isset(n, false);//表示结果中此位置是否已放置
    sort(people.begin(), people.end(), compare);

    for(int i = 0; i < n; i++){//从低到高遍历
        int cnt = 0, dst = people[i][1], j;
        for(j = 0; j < n && cnt < dst; j++){
            if(!isset[j])cnt++;
        }
        while(isset[j])j++;
        isset[j] = true;
        res[j] = people[i];
    }
    return res;
}

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
            if(!Isset[j] || res[j][0] == people[i][0])empty++;//注意遇到相等值也要+1
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