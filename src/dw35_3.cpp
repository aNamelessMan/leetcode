#include<bits/stdc++.h>
using namespace std;

int subArraySum(int i, int j, long p[]){
    if(i == 0)return *(p+j);
    else    return (*(p+j)) - (*(p + i - 1));
}
//TLE
int BFminSubarray(vector<int>& nums, int p) {
    unsigned long res = -1;
    long presum[nums.size()];
    presum[0] = nums[0];
    for(unsigned i = 1; i < nums.size(); i++){
        presum[i] = presum[i - 1] + nums[i];
    }
    //特殊情况
    if(presum[nums.size() - 1] % p == 0)return 0;

    for(unsigned i = 0; i < nums.size(); i++){
        for(unsigned j = i; j < nums.size(); j++){
            //注意%的优先级大于-
            if( (presum[nums.size() - 1] - subArraySum(i, j, presum )) % p == 0 && (j - i + 1) < res){
                res = (j - i + 1);
            }
        }
    }

    if(res == nums.size())return -1;
    return res;
}

int minSubarray(vector<int>& nums, int p) {

}

int main(){
    vector<int> nums{1000000000,1000000000,1000000000};
    int p = 3;
    //1
    cout << minSubarray(nums, p) << endl;
}