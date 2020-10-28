#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了92.42% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了31.77% 的用户
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for(auto &i:arr){
        freq[i]++;
    }
    set<int> f;
    for(auto i = freq.begin(); i != freq.end(); i++){
        if(f.count(i->second))return false;
        f.insert(i->second);
    }
    return true;
}

int main(){
    cout << 1 << endl;
}