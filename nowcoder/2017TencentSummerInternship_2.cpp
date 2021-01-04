#include <bits/stdc++.h>
using namespace std;
//https://www.nowcoder.com/question/next?pid=1725829&qid=44802&tid=40376150
void process(string s){
    int n = s.size(), i = 0;
    while(i < n){
        if(i == 0 || (s[i] >= 'A' && s[i] <= 'Z') || (s[i - 1] >= 'a' && s[i - 1] <= 'z')){
        }else{
            int p1 = i - 1, p2 = i;
            while(p1 >= 0 && s[p1] >= 'A' && s[p1] <= 'Z'){
                swap(s[p1], s[p2]);
                p1--;
                p2--;
            }
        }
        i++;
    }
    cout << s << endl;
}

int main(){
    string tmp;
    while(cin >> tmp){
        process(tmp);
    }
}