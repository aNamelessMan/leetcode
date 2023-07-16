#include <vector>
#include <string>
#include <iostream>
using namespace std;


static bool compare(const string& l, const string& r){
    size_t s = min(l.size(), r.size());
    for(int i = 0; i < s; i++){
        if(l[i] != r[i]){
            return l[i] < r[i];
        }
    }
    if(l.size() == r.size())return true;
    if(l.size() < r.size())return compare(l, r.substr(s));
    return compare(l.substr(s), r);
}
// 执行用时：4 ms, 在所有 C++ 提交中击败了97.85% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了64.26% 的用户
static bool cmp(const string& str1, const string& str2){
    return str1 + str2 < str2 + str1;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

string minNumber(vector<int>& nums) {
    //每个要加入的数字的最高位一定是目前未加入数字中最小的
    vector<string> vstr;
    for(auto i:nums){
        vstr.push_back(to_string(i));
    }
    sort(vstr.begin(), vstr.end(), compare);
    string res;
    for(auto &str:vstr){
        res += str;
    }
    return res;
}

int main(){
    vector<int> nums = {0,0,0};
    cout << minNumber(nums) << endl;
}