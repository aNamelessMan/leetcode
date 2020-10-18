#include<bits/stdc++.h>
using namespace std;
//没写出来 Wroooooooooooooooong!
multimap<int, int> a_s;
int WrongbestTeamScore(vector<int>& scores, vector<int>& ages) {
    int res = 0;
    for(int i = 0; i < (int)scores.size(); i++){
        a_s.insert({ages[i], scores[i]});
    }
    //需要全部比较？
    for(auto p = a_s.begin(); p != a_s.end(); p++){
        int t = (*p).second;
        auto i = p;
        i++;
        for(; i != a_s.end(); i++){
            if((*i).first > (*p).first && (*i).second < (*p).second)continue;
            else t += (*i).second;
        }
        if(t > res)res = t;
    }
    return res;
}

int main(){
    vector<int> scores({1,3,5,10,15});
    vector<int> ages({1,2,3,4,5});
    WrongbestTeamScore(scores, ages);
    cout << 1 << endl;
}