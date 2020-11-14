#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了5.66% 的用户
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> res;
    unordered_map<int, int> idx;
    int n = arr2.size(), m = arr1.size();
    vector<int> cnt(n, 0);//记录arr2中的元素在arr1中出现多少次
    vector<int> notin;
    for(int i = 0; i < n; i++){
        idx[arr2[i]] = i;
    }
    for(int i = 0; i < m; i++){
        if(idx.count(arr1[i])){
            cnt[idx[arr1[i]]]++;
        }else{
            notin.push_back(arr1[i]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < cnt[i]; j++){
            res.push_back(arr2[i]);
        }
    }
    int k = notin.size();
    sort(notin.begin(), notin.end());
    for(int i = 0; i < k; i++){
        res.push_back(notin[i]);
    }
    return res;
}

int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> res = relativeSortArray(arr1, arr2);
    for(auto &i:res){
        cout << i << endl;
    }
    cout << 1 << endl;
}