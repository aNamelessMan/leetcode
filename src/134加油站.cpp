#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了92.61% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了6.77% 的用户
/*
题解的解法，主要注意到两点
    1.  总油量大于大于总消耗时  一定有解
    2.  当到达某一站点时，若油量小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。
可以把整个路程分为两段，一段总gas-cost为负，一段总gas-cost为正，唯一解就在负数到正数分界线

*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, sum = 0, start = 0, n = gas.size();
    for(int i = 0; i < n; i++){
        total += (gas[i] - cost[i]);
        sum += (gas[i] - cost[i]);
        if(sum < 0){
            start = i + 1;
            sum = 0;
        }
    }
    return total >= 0?start:-1;
}

// 执行用时：144 ms, 在所有 C++ 提交中击败了28.44% 的用户
// 内存消耗：10 MB, 在所有 C++ 提交中击败了5.23% 的用户
//暴力解法
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int cur = 0, n = gas.size();
    for(int i = 0; i < n; i++){
        int cur = 0;
        for(int j = i; j < n; j++){
            cur += gas[j];
            cur -= cost[j];
            if(cur < 0)break;
        }
        if(cur < 0)continue;
        for(int j = 0; j < i; j++){
            cur += gas[j];
            cur -= cost[j];
            if(cur < 0)break;
        }
        if(cur < 0)continue;
        else return i;
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}