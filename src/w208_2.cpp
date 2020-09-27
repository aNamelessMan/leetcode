#include<bits/stdc++.h>
using namespace std;
// 执行用时：1348 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：136.6 MB, 在所有 C++ 提交中击败了100.00% 的用户

//比赛结束读题才发现......
//题目意思应该是不能停止以后又开始转
//因此无人时不能直接跳过，f和res也需要变化并加入，不然就相当于停止等人来
//思路就是模拟每轮的情况，把每轮的 {收益-轮数} 对存进去取最大值看看
int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    if(4 * boardingCost < runningCost)return -1;
    int res = 0;
    int wait = 0;
    int on = 0;
    int f = 0;
    map<int, int> r_f;
    for(auto &c:customers){
        if(c + wait == 0){f++;res -= runningCost;if(!r_f.count(res))r_f[res] = f;continue;}
        f++;
        if(c + wait > 4){
            wait = (c + wait) - 4;
            on = 4;
        }else{
            wait = 0;
            on = c + wait;
        }
        res = res + on * boardingCost - runningCost;
        if(!r_f.count(res))r_f[res] = f;
    }
    
    if(wait / 4 *4 == wait){res = res + wait * boardingCost - wait / 4 * runningCost;
        f += wait / 4;if(!r_f.count(res))r_f[res] = f;}
    else if(wait / 4 > 0){res = res + (wait / 4 * 4) * boardingCost - wait / 4  * runningCost;
        f += wait / 4;if(!r_f.count(res))r_f[res] = f;
        wait %= 4;res = res + wait * boardingCost - runningCost;
        f++;if(!r_f.count(res))r_f[res] = f;}
    else{f++;res = res + wait * boardingCost - runningCost;if(!r_f.count(res))r_f[res] = f;}

    res = (*(--r_f.end())).first;
    f = (*(--r_f.end())).second;
    if(res > 0)return f;
    return -1;
}

int main(){
    vector<int> customers{10, 10, 1, 0, 0};//4 4 
    cout << minOperationsMaxProfit(customers, 43, 54) << endl;
}