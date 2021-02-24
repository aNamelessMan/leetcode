#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了95.65% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了84.22% 的用户
int minArray(vector<int>& numbers) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    if(numbers[l] < numbers[r])return numbers[l];
    while(l < r){
        int mid = (l + r) / 2;
        if(numbers[mid] > numbers[r]){
            l = mid + 1;
        }else if(numbers[mid] < numbers[r]){
            r = mid;
        }else{//!!!!!!! 相等时无法判断，但可以去除h不影响结果，因为还有重复的在范围内
            r--;
        }

    }
    return numbers[r];
}

int main(){
    cout << "print sth." << endl;
}