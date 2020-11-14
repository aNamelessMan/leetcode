#include<bits/stdc++.h>
using namespace std;

bool wrongcanDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> same;//相同数字的组数
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int m = 0;//最多相同数字的一组有多少个
    for(int i = 0; i < n;){
        int cnt = 0, t = nums[i];
        while(i + cnt < n && nums[i + cnt] == t){
            cnt++;
        }
        m = max(m, cnt);
        i += cnt;
        same[cnt]++;
    }
    for(auto i:quantity){
        int t = i;
        if(same[i] > 0)same[i]--;
        else{
            while(same[i] <= 0 && i <= m){
                i++;
            }
            if(i > m)return false;
            same[i]--;
            same[i - t]++;
        }
    }
    return true;
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    vector<int> qua = {2,3};
    cout << wrongcanDistribute(nums, qua) << endl;
}