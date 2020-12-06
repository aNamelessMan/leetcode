#include<bits/stdc++.h>
using namespace std;

string interpret(string command) {
    int n = command.size();
    string res;
    if(n == 0)return res;
    for(int i = 0; i < n; ){
        if(command[i] == 'G'){
            res += 'G';
            i++;
        }else{
            if(i + 3 < n && command[i + 1] == 'a'){
                res += "al";
                i += 4;
            }else{
                res += 'o';
                i += 2;
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}