#include <vector>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

// 执行用时：184 ms, 在所有 C++ 提交中击败了5.25% 的用户
// 内存消耗：86.8 MB, 在所有 C++ 提交中击败了5.01% 的用户
//单调栈    2021.6.7自己的解法
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> idx;
    int i = 0;
    idx.push(i);
    i++;
    while(i < n){
        if(idx.empty() || temperatures[i] <= temperatures[idx.top()]);
        else{
            while(!idx.empty() && temperatures[i] > temperatures[idx.top()]){//注意维护递减栈要把所有小于当前元素的值出栈
                res[idx.top()] = i - idx.top();
                idx.pop();
            }
        }
        idx.push(i);
        i++;
    }
    return res;
}

vector<int> BFdailyTemperatures(vector<int>& T) {//暴力解法TLE  O(N^2)
    vector<int> res;
    for(unsigned j = 0; j < T.size(); j++){
        unsigned i = j;
        while(i < T.size() && T[j] >= T[i]){
            i++;
        }
        if(i == T.size())
            res.push_back(0);
        else
            res.push_back(i - j);
    }
    return res;
}
// 执行用时：116 ms, 在所有 C++ 提交中击败了83.96% 的用户
// 内存消耗：35.1 MB, 在所有 C++ 提交中击败了21.62% 的用户
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size(), 0);
    stack<int> st;
    for(unsigned i = 0; i < T.size(); i++){

        while(!st.empty() && T[i] > T[st.top()]){//遍历到更大值后就将栈顶出栈，因此一定是唯一一个也是第一个更大值，距离就是两者差
                                                                                      //并且while一直出栈，直到栈顶元素为空 或 大于当前值，因此栈内元素一定是递减的，称为递减栈
            auto t = st.top();
            st.pop();
            res[t] = i - t;
        }

        st.push(i);//按顺序入栈，栈内元素均暂未找到更大值
    }
    return res;
}

int main(){
    vector<int> temp{34,80,80,34,34,80,80,80,80,34};
    vector<int> res = dailyTemperatures(temp);
    for(auto &t:res){
        cout << t << ",";
    }
    cout << endl;
}