#include <bits/stdc++.h>
using namespace std;

//暴力解法  复杂度O(3^n) 16 / 45 个通过测试用例
//加上剪枝后通过
// 执行用时：100 ms, 在所有 C++ 提交中击败了73.23% 的用户
// 内存消耗：20.1 MB, 在所有 C++ 提交中击败了49.55% 的用户
bool dfs(int cur, int prek, int dst, unordered_set<int> &sts, set<pair<int, int>> &memo){
    if(cur == dst)return true;
    if(memo.find({cur, prek}) != memo.end()){//剪枝
        return false;
    }

    vector<int> ks;
    if(cur == 0){
        ks = {1};
    }else{
        ks = {prek - 1, prek, prek + 1};
    }

    for(auto k:ks){
        if(k && sts.find(cur + k) != sts.end()){//k为0时会无限递归下去，直到栈溢出
            if(dfs(cur + k, k, dst, sts, memo)){
                return true;
            }
        }
    }
    memo.insert({cur, prek});//保存此次结果防止重复计算
    return false;

}

bool canCross(vector<int>& stones) {
    int n = stones.size();
    unordered_set<int> sts;
    for(auto &st:stones){
        sts.insert(st);
    }
    set<pair<int, int>> memo;
    return dfs(0, -1, stones[n - 1], sts, memo);
}

int main(){
    vector<int> sts{0,1,3,5,6,8,12,17};
    canCross(sts);
    cout << "print sth." << endl;
}