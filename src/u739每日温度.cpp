#include <vector>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

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