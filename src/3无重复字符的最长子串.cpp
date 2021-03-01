#include<bits/stdc++.h>
using namespace std;

// 执行用时：32 ms, 在所有 C++ 提交中击败了56.47% 的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了37.25% 的用户
//2021.3.1二刷自己的写法，感觉更好
int lengthOfLongestSubstring(string s) {
    int n = s.size(), res = 0, l = 0, r = 0;//区间左闭右开
    unordered_set<char> cs;
    while(r < n){
        while(!cs.count(s[r]) && r < n){//没遇到重复则右边界一直扩张
            cs.insert(s[r]);
            r++;
        }
        res = max(res, r - l);//只有在扩张后才可能更新
        while(s[l] != s[r]){//左边界一直收缩直到去除重复的字符
            cs.erase(s[l]);
            l++;
        }
        cs.erase(s[l]);
        l++;
        cs.insert(s[r]);
        r++;
    }
    return res;
}

// 执行用时：36 ms, 在所有 C++ 提交中击败了63.12% 的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了42.05% 的用户
int firstlengthOfLongestSubstring(string s) {
    int n = s.size(), res = 0, l = 0, r = 0;//双指针，l是第一个属于窗口的字符，r是第一个不属于窗口的字符，因此窗口长度就是r - l
    unordered_set<char> window;//在窗口内的字符集合，一定是无重复的
    while(r < n){
        auto iter = window.find(s[r]);
        if(iter == window.end()){//当前r指向的字符在窗口中无重复    新的最大值只可能在这种情况下产生
            window.insert(s[r]);
            r++;//添加进窗口
            res = max(res, r - l);
        }else{//存在重复则收缩窗口
            while(s[l] != s[r]){
                window.erase(s[l]);
                l++;
            }
            window.erase(s[l]);
            l++;
        }
    }
    return res;
}

/*
执行用时 :48 ms, 在所有 C++ 提交中击败了37.84% 的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
int BFlengthOfLongestSubstring(string s) {
    int bit[128];
    int max = 0;
    int count = 0;
    int l = s.length();
    int asc = -1;
    for(int i = 0;i < l;++i){
        for(int i = 0;i < 128;++i){
            bit[i] = 0;
        }
        count = 0;

        for(int j = i;j < l;++j){
            asc = s[j];
            if(bit[asc] == 1){
                break;
            }else{
                count++;
                if(count > max)max = count;
                bit[asc] = 1;
            }
        }
    }
    return max;
}
//2020.10.29笔试写的解法，比上面简单点
int mylengthOfLongestSubstring(string s) {
    if(s.empty())return 0;
    int res = 1;
    int l = 0, r = 1;
    
    int n = s.size();
    set<int> is;
    
    is.insert(s[0]);//忘了加这一行，到最后也没找出来...
                    //所以以后做题一定要注意初始化是否正确

    while(r < n){
        if(!is.count(s[r])){
            is.insert(s[r]);
            r++;
            int t = r - l;
            if(t > res)res = t;
        }else{
            while(s[l] != s[r]){
                is.erase(s[l]);
                l++;
            }
            is.erase(s[l]);
            l++;
            is.insert(s[r]);
            r++;
        }
    }
    return res;
}

int main(){
    cout << "print something." << endl;
}