#include<bits/stdc++.h>
using namespace std;

string largestMerge(string word1, string word2) {
    int m = word1.size(), n = word2.size(), c = 0, c1 = 0, c2 = 0, e = m + n;
    string res;
    while(c < e){
        if(c1 == m){
            res += word2[c2];
            c2++;
        }else if(c2 == n){
            res += word1[c1];
            c1++;
        }else{
            if(word1.substr(c1) > word2.substr(c2)){//用substr有点作弊的感觉，而且速度会非常慢，不过还是过了
            //当两个字符相同时，不能随便选一个，而要找出后续第一个不同的字符，然后选择更大的那个字符所在字符串的那个    复杂度会是O(n^2) 3000*3000约为1e7
                res += word1[c1];
                c1++;
            }else{
                res += word2[c2];
                c2++;
            }
        }
        c++;
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}