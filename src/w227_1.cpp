#include<bits/stdc++.h>
using namespace std;

//这两次周赛的前三题都好简单，但是第四题还是做不出来
/*17分钟就做完前三题了，做完前三题的时候排第43，然后就一直卡在第四题，最终175/3545
*/
bool check(vector<int>& nums) {
    int c = 1, n = nums.size();
    if(nums[0] < nums[n - 1])c--;
    for(int i = 1; i < n; i++){
        if(nums[i] < nums[i - 1]){
            c--;
            if(c < 0)return false;
        }
    }
    return true;
}

int main(){
    cout << "print something." << endl;
}