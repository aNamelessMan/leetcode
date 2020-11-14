#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int res = INT_MAX;
    int n = s.size();
    if(n == 0)return 0;
    vector<int> dp(n, 0);
    
}

//暴力解法  TLE
int BFminimumDeletions(string s) {//使得a在前面，b在后面
    int res = INT_MAX;
    int n = s.size();
    if(n == 0)return 0;

    for(int i = 0; i <= n; i++){//设i所在是第一个b
        int t = 0;
        for(int j = 0; j < i; j++){
            if(s[j] != 'a')t++;
        }
        for(int j = i; j < n; j++){
            if(s[j] != 'b')t++;
        }
        res = min(res, t);
    }
    return res;
}

int main(){
    cout << BFminimumDeletions("aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa") << endl;
}