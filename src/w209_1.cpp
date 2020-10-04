#include<bits/stdc++.h>
using namespace std;

int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        if(nums[nums.size() - 1] >= nums.size())return nums.size();
        for(unsigned i = 0; i <nums.size() - 1; i++){
            while(nums[i + 1] == nums[i] && i + 1 < nums.size() - 1)i++;
            for(unsigned j = nums[i]; j > nums[i + 1]; j--)
                if(i + 1 == j)return i + 1;
        }

        return -1;
}

int main(){
    vector<int> nums{0,4,3,0,4};//4 4 3 0 0 
    cout << specialArray(nums) << endl;
}