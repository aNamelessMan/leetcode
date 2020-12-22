#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了46.11% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了55.49% 的用户
//没想到直接拼接了字符串来比较...
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    string res;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        res += to_string(nums[i]);
    }
    return res[0] == '0' ? "0":res;
}

int main(){
    cout << 1 << endl;
}