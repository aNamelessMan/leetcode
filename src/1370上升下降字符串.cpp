#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.00% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了26.48% 的用户
string sortString(string s) {
    string res;
    int n = s.size(), cnt = 0;
    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }
    int i = 0, pre = -1;
    while(cnt < n){
        pre = -1;
        while(i != 26){
            for(i = pre + 1; i < 26; i++){
                if(freq[i] > 0){
                    res += (char)('a' + i);
                    freq[i]--;
                    cnt++;
                    pre = i;
                }
            }
        }
        pre = 26;
        while(i != -1){
            for(i = pre - 1; i >= 0; i--){
                if(freq[i] > 0){
                    res += (char)('a' + i);
                    freq[i]--;
                    cnt++;
                    pre = i;
                }
            }
        }
    }
    return res;
}

int main(){
    cout << sortString("rat") << endl;
}