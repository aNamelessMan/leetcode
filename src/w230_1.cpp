#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int n = items.size(), res = 0;
    if(ruleKey == "type"){
        for(int i = 0; i < n; i++){
            if(items[i][0] == ruleValue)res++;
        }
    }
    if(ruleKey == "color"){
        for(int i = 0; i < n; i++){
            if(items[i][1] == ruleValue)res++;
        }
    }
    if(ruleKey == "name"){
        for(int i = 0; i < n; i++){
            if(items[i][2] == ruleValue)res++;
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}