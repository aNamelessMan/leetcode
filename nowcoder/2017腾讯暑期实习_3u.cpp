#include <bits/stdc++.h>
using namespace std;

/*
关于复杂度的预估

1<=N<=100000
一般系统1s能跑的算法量级是不足1e8的
所以n=1e5时，平方复杂度肯定不可行
需要O(n)或O(nlogn)

所以不要白费力气去写暴力解法了
*/

//答案正确:恭喜！您提交的程序通过了所有的测试用例
//求差值对的个数应该想到要排序的...
//复杂度应该是O(n)
void process(){
    int cnt = 0;
    while(cin >> cnt){
        vector<int> data;
        int t = 0;
        for(int i = 0; i < cnt; i++){
            cin >> t;
            data.push_back(t);
        }
        
        sort(data.begin(), data.end());
        vector<int> num(cnt, 0);
        bool hasSame = false;
        int i = 0;
        while(i < cnt){
            int j = i + 1;
            while(j < cnt && data[j] == data[i]){
                j++;
            }
            int n = j - i;
            num[i] = n;
            if(n > 1){
                hasSame = true;
            }
            i = j;
        }
        if(hasSame){//如果有相同值，则最小差一定是0，要将所有相同值所形成的差值为0的对数加起来
            int mnc = 0;
            for(auto n:num){
                if(n > 1)mnc += n * (n - 1) / 2;
            }
            cout << mnc << " ";
        }else{//将所有差值最小的对数相加
            int mnc = 0, mnv = INT_MAX;
            int pre = 0;
            for(int i = 1; i < cnt; i++){
                if(num[i]){
                    if(data[i] - data[pre] < mnv){
                        mnv = data[i] - data[pre];
                        mnc = num[i] * num[pre];
                    }else if(data[i] - data[pre] == mnv){
                        mnc += num[i] * num[pre];
                    }
                    pre = i;
                }
            }
            cout << mnc << " ";
        }
        //相差最大的对数就是最大值个数乘上最小值个数，注意特殊处理最大最小相同情况即可
        for(i = cnt - 1; i >= 0; i--){
            if(num[i])break;
        }
        if(i == 0){//即最大最小值相同
            cout << num[0] * (num[0] - 1)/2 << endl;
        }else{
            cout << num[0] * num[i] << endl;
        }
    }
}
//复杂度O(n^2)
void BFprocess(){
    int cnt = 0;
    while(cin >> cnt){
        vector<int> data;
        int t = 0;
        for(int i = 0; i < cnt; i++){
            cin >> t;
            data.push_back(t);
        }
        unordered_map<int, int> m;//{差值，对数}
        for(int i = 0; i < cnt; i++){
            for(int j = i + 1; j < cnt; j++){
                m[abs(data[i] - data[j])]++;
            }
        }
        int mxv = INT_MIN, mnv = INT_MAX, mxc, mnc;
        for(auto iter = m.begin(); iter != m.end(); iter++){
            if(iter->first >= mxv){
                mxv = iter->first;
                mxc = iter->second;
            }
            if(iter->first <= mnv){
                mnv = iter->first;
                mnc = iter->second;
            }
        }
        cout << mnc << " " << mxc << endl;
    }
}

int main(){
    process();
    return 0;
}