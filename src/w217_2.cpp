#include<bits/stdc++.h>
using namespace std;

// 执行用时：424 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：97.7 MB, 在所有 C++ 提交中击败了100.00% 的用户
//这道题与402一模一样改下参数就行，都是用单调栈做的，但是当时做的时候没用单调栈也过了，所以就不会做超时了...
vector<int> mostCompetitive(vector<int>& nums, int k) {
    //让高位上的数字尽可能小，采用递增栈
    int n = nums.size(), i = n - k;//i是需要丢弃的数字个数
    vector<int> res;
    for (int c : nums) {
        while (i && res.size() && res.back() > c) {//如果   还可以继续丢 && res不为空 && 栈顶大于当前
            res.pop_back();                        //丢弃栈顶（即出栈）并把可丢弃数字减一
            --i;
        }
        res.push_back(c);
    }
    res.resize(k);//最后递增栈大小可能大于需要保留的大小，优先保留前面的

    return res;
}

//72 / 85 个通过测试用例    TLE O(nlogn + k * n)
bool isSmaller(pair<int, int> &v1, pair<int, int> &v2){//优先按值从小到大排，其次按下标从小到大排
    if(v1.first != v2.first)return v1.first < v2.first;
    return v1.second < v2.second;
}
    
vector<int> BBFmostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();//e是右开区间
    vector<int> res;
    vector<pair<int, int>> vip;
    
    if(n == k){
        sort(nums.begin(), nums.end());
        return nums;
    }
    
    for(int i = 0; i < n; i++){
        vip.push_back({nums[i], i});
    }
    sort(vip.begin(), vip.end(), isSmaller);
    
    int s = 0, e = n - k + 1, minidx = -1;
    while(k > 0){
        
        for(int i = 0; i < n; i++){
            if(vip[i].second >= s && vip[i].second < e){
                minidx = vip[i].second;
                res.push_back(vip[i].first);
                break;
            }
        }
        
        s = minidx + 1;
        k--;
        e = n - k + 1;
    }
    
    return res;
}

//83 / 85 个通过测试用例    TLE O(k * n)
vector<int> BFmostCompetitive(vector<int>& nums, int k) {
    int n = nums.size(), s = 0, e = n - k + 1;//e是右开区间
    vector<int> res;
    while(k > 0){
        int t = INT_MAX, minidx = -1;
        for(int i = s; i < e; i++){
            t = min(t, nums[i]);
        }
        for(int i = s; i < e; i++){
            if(nums[i] == t){
                minidx = i;
                break;
            }
        }
        res.push_back(t);
        s = minidx + 1;
        k--;
        e = n - k + 1;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}