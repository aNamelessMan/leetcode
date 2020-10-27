#include<bits/stdc++.h>
using namespace std;
// 执行用时：20 ms, 在所有 C++ 提交中击败了79.56% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了9.69% 的用户
//时间复杂度为O(nlogn)，写复杂了，还不如直接排序，时间复杂度是一样的
int BFlongestConsecutive(vector<int>& nums) {
    if(nums.empty())return 0;
    int res = 1;
    set<int> no;
    for(auto &i:nums){
        no.insert(i);//set的插入复杂度为O(logn)
    }
    auto i = no.begin();
    int t = 1;
    int f = *i;i++;
    for(;i != no.end(); i++){
        if(*i - (long)f == 1){
            t++;
            if(t > res)res = t;
        }else{
            t = 1;
        }
        f = *i;
    }
    return res;
}
// 执行用时：16 ms, 在所有 C++ 提交中击败了95.98% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了13.98% 的用户
//关键在于连续，前面尝试过的值后面不用再找，但复杂度应该也不是O(n)
int longestConsecutive(vector<int>& nums) {
    if(nums.empty())return 0;
    int res = 1;
    unordered_set<long> no(nums.begin(), nums.end());//注意这里必须是long，否则下面的用例结果会是2
                                                    //否则count(2147483648)返回不是0

    for(auto &i:nums){
        long pre = (long)i - 1, next = (long)i + 1;
        while(no.count(pre))
            no.erase(pre--);
        while(no.count(next))
            no.erase(next++);
        if(next - pre - 1 > res)res = next - pre - 1;
    }

    return res;
}

int main(){
    vector<int> nums({2147483647,-2147483648});
    cout << longestConsecutive(nums) << endl;
}