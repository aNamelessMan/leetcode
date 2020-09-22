#include<bits/stdc++.h>
using namespace std;
//递归  99 / 101 个通过测试用例 TLE
bool BFisInterleave(string s1, string s2, string s3) {
    if(!s3.size())return !s1.size() && !s2.size();
    else if(!s2.size())return s1 == s3;
    else if(!s1.size())return s2 == s3;

    else if(s1[0] == s3[0] && s2[0] == s3[0])return (BFisInterleave(s1.substr(1), s2, s3.substr(1)) || BFisInterleave(s1, s2.substr(1), s3.substr(1)));
    else if(s1[0] == s3[0])return BFisInterleave(s1.substr(1), s2, s3.substr(1));
    else if(s2[0] == s3[0])return BFisInterleave(s1, s2.substr(1), s3.substr(1));
    else return false;
}

bool isInterleave(string s1, string s2, string s3) {
    // if(s1.size() + s2.size() != s3.size())return false;
    // if(!s3.size())return !s1.size() && !s2.size();
    // else if(!s2.size())return s1 == s3;
    // else if(!s1.size())return s2 == s3;
    // //限定s3长度是s1和s2的长度和
    // bool dp[s1.size()][s2.size()];
    // dp[0][0] = true;
    // for(unsigned i = 1; i < s1.size(); i++){
    //     dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    // }
    // for(unsigned i = 1; i < s2.size(); i++){
    //     dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    // }
    // for(unsigned i = 1; i < s1.size(); i++){
    //     for(unsigned j = 1; j < s2.size(); j++){
    //         dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])||(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
    //     }
    // }
    // return dp[s1.size() - 1][s2.size() - 1];
}

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << isInterleave(s1, s2, s3) << endl;
}