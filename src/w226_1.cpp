#include<bits/stdc++.h>
using namespace std;

//第226场周赛，这次的题目比较简单，做完第三题的时候排名还是220+名，可惜第四题写不出来，只会暴力解法超时了...
//最终排名593/4033
int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> box;
    for(int i = lowLimit; i <= highLimit; i++){
        int t = i, cnt = 0;
        while(t){
            cnt += t % 10;
            t /= 10;
        }
        box[cnt]++;
    }
    int mxv = INT_MIN;
    for(auto iter = box.begin(); iter != box.end(); iter++){
        if(iter->second > mxv){
            mxv = iter->second;
        }
    }
    return mxv;
}

int main(){
    cout << "print something." << endl;
}