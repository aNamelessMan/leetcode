#include<bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了33.53% 的用户
// 内存消耗：9.6 MB, 在所有 C++ 提交中击败了59.50% 的用户
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while(i < j){
        if(numbers[i] + numbers[j] == target)return {i + 1, j + 1};
        else if(numbers[i] + numbers[j] < target)i++;
        else j--;
    }
    return {-1, -1};
}

int main(){
    cout << 1 << endl;
}