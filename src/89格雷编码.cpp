#include<bits/stdc++.h>
using namespace std;
// 执行用时：24 ms, 在所有 C++ 提交中击败了44.03% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了5.10% 的用户
vector<int> grayCode(int n) {
    //开头一定是00...00b
    //保存已用过的每个数
    //从第一位开始尝试对每一位取反，未用过则用，用过尝试下一位
    vector<int> res;
    set<int> used;
    used.insert(0);
    res.push_back(0);

    vector<int> m;
    int t = 1;
    for(int i = 0; i < n; i++){
        m.push_back(t);
        t *= 2;
    }
    int e = 2*t;

    vector<int> pre(n, 0);
    for(int i = 0; i < e; i++){
        for(int j = 0; j < n; j++){
            pre[j] = !pre[j];
            int num = 0;
            for(int k = 0; k < n; k++){
                num += pre[k] * m[k];
            }
            if(!used.count(num)){
                used.insert(num);
                res.push_back(num);
                break;
            }else{
                pre[j] = !pre[j];
                continue;
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}