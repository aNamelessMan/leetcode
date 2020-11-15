#include<bits/stdc++.h>
using namespace std;
//9 / 86 个通过测试用例
int res = INT_MAX;    

void dfs(int l, int r, int cur, int step, vector<int>& nums, int n){
    if(cur == 0){
        res = min(res, step);
        return;
    }
    if(cur < 0 || l > r)return;
    if(l < n)
        dfs(l + 1, r, cur - nums[l], step + 1, nums, n);
    if(r > -1)
        dfs(l, r - 1, cur - nums[r], step + 1, nums, n);
}    

int BFminOperations(vector<int>& nums, int x) {
    if(accumulate(nums.begin(), nums.end(), 0) < x)return -1;
    int n = nums.size();
    dfs(0, n - 1, x, 0, nums, n);
    if(res == INT_MAX)return -1;
    return res;
}

int minOperations(vector<int>& nums, int x) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    if(s < x)return -1;
    int n = nums.size(), sum = s - x;

    //54 / 86 个通过测试用例
    /*for(int i = n; i >= 0; i--){
        for(int j = 0; j <= n - i; j++){
            if(accumulate(nums.begin() + j, nums.begin() + i + j, 0) == sum)
                return n - i;
        }
    }*/
    //37 / 86 个通过测试用例
    /*int res = INT_MAX;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            if(accumulate(nums.begin() + i, nums.begin() + i + j, 0) == sum)
                res = min(res, n - j);
        }
    }
    
    if(res != INT_MAX)return res;*/
    return -1;
}

int main(){
    //vector<int> nums({1,1,4,2,3});
    vector<int> nums({8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309});
    //vector<int> nums({1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136});
    //cout << accumulate(nums.begin(), nums.end(), 0) << endl;
    cout << minOperations(nums, 134365) << endl;
}