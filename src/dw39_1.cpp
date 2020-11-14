#include<bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> res(n, 0);
    if(k == 0)return res;
    if(k > 0){
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i + 1; j <= i + k; j ++){
                if(j < n)sum += code[j];
                else sum += code[j - n];
            }
            res[i] = sum;
        }
    }else{
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i - 1; j >= i + k; j --){
                if(j >= 0)sum += code[j];
                else sum += code[n + j];
            }
            res[i] = sum;
        }
    }
    return res;
}

int main(){
    vector<int> c({2, 4, 9, 3});
    vector<int> res = decrypt(c, -2);
    cout << 1 << endl;
}