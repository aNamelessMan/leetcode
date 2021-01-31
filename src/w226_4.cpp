#include<bits/stdc++.h>
using namespace std;

/*
暴力解法为O(n^3)
n = 2000
n^3 = 8 * 10^9 > 1 * 10^8
因此虽然2000看上去很小，但是三次方复杂度的暴力解法也是不行的

如果有平方复杂度的解法一定可行
如果对于s，我们可以用O(1)的时间来知道s[i...j], j >= i是否为一个回文串，那么这个问题就有O(N^2)的解。
因为可以用两个索引i和j，我们只需要判断s[0...i], s[i+1...j], s[j...n-1]是否为回文串即可。

问题就变成了如何用O(1)的时间来知道s[i...j]是否为一个回文串的问题，用区间动态规划即可。
*/

/*
平方做法，令 f[i][j] 代表 s 闭区间连续子串 [i,j] 是否是回文串即可。
具体转移见代码。
*/
int f[2005][2005],n,l,r,len,tmp;
bool checkPartitioning(string s) {
    n=s.size();
	memset(f,0,sizeof(f));
    for (len=0; len<n; len++) {
		for (l=n-len-1; l>=0; l--) {
    		r=l+len;
    		if (r-l<=1) {   //一个字母或两个字母，直接判断（用作 dp 基础）。
    			f[l][r]=(s[l]==s[r]);
			}
			else {      //多个字母，利用两端字母 以及 除去两端字母剩下的(即 f[l+1][j-1]) 来判断。
				f[l][r]=(s[l]==s[r] && f[l+1][r-1]);
			}
		}
    }
	for (l=n-2; l>0; l--) {
    	for (r=n-2; r>=l; r--) {    //枚举中间那个串 [l,r]
    		if (f[0][l-1] && f[l][r] && f[r+1][n-1]) {
				return 1;
			}
		}
	}
	return 0;
}

//O(n^3)
//75 / 81 个通过测试用例    TLE
/*
substr函数会调用构造函数生成一个临时对象
只有const引用可以绑定到临时对象上
采用const引用应该可以减少 函数调用值传递时的一次拷贝构造函数调用的开销
但是还是超时了...
*/
bool isSp(const string &s, unordered_map<string, bool> &dps){//判断s是否为回文串
    if(dps.find(s) != dps.end())return dps[s];
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n - i - 1]){
            dps[s] = false;
            return false;
        }
    }
    dps[s] = true;
    return true;
} 

bool isTp(const string &s, unordered_map<string, bool> &dps, unordered_map<string, bool> &dpt){//判断s是否能分为非空两个回文串
    if(dpt.find(s) != dpt.end())return dpt[s];
    int n = s.size();
    for(int l = 1; l < n; l++){
        if(isSp(s.substr(0, l), dps) && isSp(s.substr(l), dps)){
            dpt[s] = true;
            return true;
        }
    }
    dpt[s] = false;
    return false;
}
    
bool BFcheckPartitioning(string s) {
    int n = s.size();
    unordered_map<string, bool> dps;
    unordered_map<string, bool> dpt;
    for(int l = 1; l < n - 1; l++){
        if(isSp(s.substr(0, l), dps) && isTp(s.substr(l), dps, dpt))return true;
    }
    return false;
}

int main(){
    cout << "print something." << endl;
}