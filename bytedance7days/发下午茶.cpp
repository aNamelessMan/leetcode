#include <bits/stdc++.h>
using namespace std;

/*
难以直接求出所需的最少时间
采用的是二分查找，不断去判断时间是否足够送完
*/
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：3.2 MB, 在所有 C++ 提交中击败了75.00% 的用户
bool check(vector<int>& T, int K, int limit){//判断K个字节君能否在时间limit内送完
    //先把一个字节君的时间用完再用下一个,将在运输途中的时间减到最少
    int workspace = 0, index = 0;//workspace是下一个要送的工间，index是该工间已经送了的份数
    for(int i = 0; i < K; i++){
        int left = limit - workspace - 1;//left是此字节君还剩的时间
        while(left > 0 && workspace < (int)T.size()){
            int count = min(left, T[workspace] - index);//送的份数
            left -= count;
            index += count;
            if(index == T[workspace]){//此工间已送完
                workspace++;
                index = 0;
                left--;
            }
        }
    }
    return workspace == (int)T.size();
}

int bs(vector<int>& T, int K){
    int l = 0, r = 20000000;//左开右闭
    while(l < r){
        if(r - l == 1)return r;//防止死循环
        int mid = (l + r) / 2;
        if(check(T, K, mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}

int main(){
    int K, N, t;
    vector<int> T;
    while(cin >> K){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> t;
            T.push_back(t);
        }
        cout << bs(T, K) << endl;//打印出结果而不是return返回值...因为这个所以运行错误卡住了...
    }
}