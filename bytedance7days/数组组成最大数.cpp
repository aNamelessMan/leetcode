#include <bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：3.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
//就是leetcode第179题
#include <bits/stdc++.h>
using namespace std;

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
    string input;
    while(cin >> input){
        int i = 1, n = input.size();//注意忽略输入的[]
        vector<int> num;
        while(i < n - 1){
            int c = 0;
            while(i < n - 1 && input[i] != ','){
                c = 10 * c + input[i] - '0';
                i++;
            }
            num.push_back(c);
            i++;
        }
        cout << largestNumber(num) << endl;
    }
}