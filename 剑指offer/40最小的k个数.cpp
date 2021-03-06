#include <bits/stdc++.h>
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了47.55% 的用户
// 内存消耗：18.5 MB, 在所有 C++ 提交中击败了79.38% 的用户
int part(vector<int>& arr, int l, int h){
    int toset = l;
    for(int i = l; i < h; i++){
        if(arr[i] < arr[h]){
            std::swap(arr[i], arr[toset]);
            toset++;
        }
    }
    std::swap(arr[h], arr[toset]);
    return toset;
}

void quicksort(vector<int>& arr, int l, int h, int k){
    if(l < h){
        int p = part(arr, l, h);
        if(p == k || p == k - 1)return;
        quicksort(arr, l, p - 1, k);
        quicksort(arr, p + 1, h, k);
    }
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    quicksort(arr, 0, arr.size() - 1, k);
    vector<int> res;
    for(int i = 0; i < k; i++){
        res.push_back(arr[i]);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}