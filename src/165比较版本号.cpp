#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了34.99% 的用户
int compareVersion(string version1, string version2) {
    int m = version1.size(), n = version2.size();
    int i = 0, j = 0;
    while(i < m || j < n){
        string s;
        while(i < m && version1[i] != '.'){
            s.push_back(version1[i]);
            i++;
        }
        i++;
        int v1 = 0;
        if(s.empty()){}
        else v1 = atoi(s.c_str());

        string t;
        while(j < n && version2[j] != '.'){
            t.push_back(version2[j]);
            j++;
        }
        j++;
        int v2 = 0;
        if(t.empty()){}
        else v2 = atoi(t.c_str());

        if(v1 == v2)continue;
        else if(v1 > v2)return 1;
        else return -1;
    }
    return 0;
}

int main(){
    cout << 1 << endl;
}