#include <bits/stdc++.h>
using namespace std;
//5503. 所有奇数长度子数组的和
    // 1 <= arr.length <= 100
    // 1 <= arr[i] <= 1000

// 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

// 子数组 定义为原数组中的一个连续子序列。

// 请你返回 arr 中 所有奇数长度子数组的和 。
// 输入：arr = [10,11,12]
// 输出：66
int sumOddLengthSubarrays(vector<int>& arr) {
    //int start = 0, end = 0;
    vector<int> tmp;
    int res = 0;
    if(arr.size() % 2){
        for(unsigned i = 1; i <= arr.size(); i += 2){
            for(unsigned j = 0; j < arr.size(); j += 1){
                if(j + i > arr.size())break;
                for(unsigned k = j; k < j + i; k++){
                    res += arr[k];
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr{1, 4, 2, 5, 3};
    cout << sumOddLengthSubarrays(arr) << endl;
}
