#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了81.03% 的用户
string myremoveKdigits(string num, int k) {
    //用光删除名额k之前确保递增
    int n = num.size(), keep = n - k;
    string res;
    for(char c:num){
        while(k && !res.empty() && res.back() > c){
            res.pop_back();
            k--;
        }
        res += c;
    }
    res = res.substr(0, keep);
    int i = 0;
    while(i < n - k && res[i] == '0'){
        i++;
    }
    res = res.substr(i);
    return res.empty()?"0":res;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了91.37% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了42.84% 的用户
//今天做周赛才知道这道题应该用单调栈来做
// 316. Remove Duplicate Letters
// 321. Create Maximum Number
// 402. Remove K Digits
// 这三道题都用到了 stack 来求原序列中不打乱相对次序的最小子序列的技巧，然而 OJ 上并没有把它们归为 similar problems 
//题解参见w217_2.cpp
string removeKdigits(string num, int k) {
    string res = "";
    int n = num.size(), keep = n - k;
    for (char c : num) {
        while (k && res.size() && res.back() > c) {
            res.pop_back();
            --k;
        }
        res.push_back(c);
    }
    res.resize(keep);
    while (!res.empty() && res[0] == '0') res.erase(res.begin());
    return res.empty() ? "0" : res;
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了36.82% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了42.28% 的用户
//边界太麻烦了，错了好多次...
string BFremoveKdigits(string num, int k) {
    string res;
    char minn = 58;
    int minidx = 0, n = num.size(), preidx = -1;
    if(k == n)return "0";
    if(k == 0)return num;
    while(k && preidx < n - 1 - k){
        minn = 58;
        for(int i = preidx + 1; i <= preidx + k + 1 && i < n; i++){
            if(num[i] < minn){
                minn = num[i];
                minidx = i;
            }
        }
        if(minn != '0' || !res.empty())
            res += minn;
        k -= (minidx - preidx - 1);
        preidx = minidx;
    }
    for(int i = minidx + 1; i < n - k; i++){
        res += num[i];
    }
    if(res.empty())return "0";
    return res;
}

int main(){
    cout << myremoveKdigits("1173", 2) << endl;
}