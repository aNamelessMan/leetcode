#include <iostream>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了64.45% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了78.23% 的用户
//21.5.8二刷，找规律即可，注意处理特殊情况，比之前写的更简洁
string secondconvert(string s, int numRows) {
    if(numRows == 1)return s;
    string res;
    int n = s.size(), gapsum = 2 * numRows - 2;
    for(int base = 0, gapbase = gapsum; base < numRows && base < n; base ++, gapbase -= 2){
        int idx = base, gap = gapbase;
        while(idx < n){
            res += s[idx];
            idx += gap;
            if(gap == 0){//上一跳为0时需要计算gap后再跳一次
                gap = gapsum - gap;
                idx += gap;
            }else if(gap == gapsum){//上一跳为gapsum时，下一跳gap不变
                gap = gap;
            }else{//普通情况
                gap = gapsum - gap;
            }
        }
    }
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了98.21% 的用户
//忘了考虑边界情况：numRows == 1 导致第三次提交才成功
//判断s.size() <= numRows会简化有些计算，不影响正确性，可以省略
string convert(string s, int numRows) {
    if(s.size() <= numRows || numRows == 1)return s;
    int idx = 0;
    string res(s.size(), 0);
    //首尾需要特殊判断，如果不至于会导致输出两次从而溢出
    //因为首尾i=0和i=numRows-1分别会导致2*i==0 2*numRows-2*i-2==0
    int t = 0;
    while(t < s.size()){
        res[idx++] = s[t];
        t += 2*numRows - 2;
    }
    //中间部分
    for(int i = 1; i < numRows - 1; i++){
        int start = i;

        while(1){
            if(start < s.size() && i != numRows - 1){
                res[idx++] = s[start];
                start += (2*numRows-2*i-2);
                if(start < s.size() && i != 0){
                    res[idx++] = s[start];
                    start += 2*i;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
            
    }
    //尾部情况
    t = numRows - 1;
    while(t < s.size()){
        res[idx++] = s[t];
        t += 2*numRows - 2;
    }
    return res;
}
int main(){
    //"PAHNAPLSIIGYIR"
    cout << convert("AB",1) << endl;
}