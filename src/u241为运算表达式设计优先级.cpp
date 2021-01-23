#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了84.69% 的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了55.87% 的用户
//分治然后递归
vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    if (input[i] == '+') res.push_back(left[j] + right[k]);
                    else if (input[i] == '-') res.push_back(left[j] - right[k]);
                    else res.push_back(left[j] * right[k]);
                }
            }
        }
    }
    /*
    base case   不包含符号，仅仅是一个简单地数字
    */
    if (res.empty()) res.push_back(stoi(input));
    return res;
}

int main(){
    cout << "print something." << endl;
}