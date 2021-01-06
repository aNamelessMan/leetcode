#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了90.54% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了88.11% 的用户
//注意 相同字符数为3时 下标差大于等于2时即可
vector<vector<int>> largeGroupPositions(string s) {
    int n = s.size();
    vector<vector<int>> res;
    for(int i = 0; i < n;){
        int start = i;
        char startch = s[i];
        while(i < n && s[i] == startch)i++;
        int end = i - 1;
        if(end - start >= 2)res.push_back({start, end});
    }
    return res;
}

int main(){
    cout << 1 << endl;
}