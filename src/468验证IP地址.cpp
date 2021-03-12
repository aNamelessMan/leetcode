#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了90.52% 的用户
//错了很多次    感觉这种题就是考能不能想到有些测试用例
bool isIPv6(string &ip){
    int n = ip.size(), i = 0, cnt = 0;
    while(i < n){
        int s = i;
        while(i < n && ip[i] != ':'){
            if(i - s > 4)return false;
            else if((ip[i] >= '0' && ip[i] <= '9') || (ip[i] >= 'a' && ip[i] <= 'f') || (ip[i] >= 'A' && ip[i] <= 'F')){
                i++;
            }else{
                return false;
            }
        }
        if(i == s || i - s > 4)return false;
        i++;
        cnt++;
    }
    if(cnt == 8 && ip[n - 1] != ':')return true;
    else return false;
}

bool isIPv4(string &ip){
    int n = ip.size(), i = 0, cnt = 0;
    while(i < n){
        int c = 0, s = i;
        while(i < n && ip[i] != '.'){
            if(i - s > 3)return false;
            else if(i == s && ip[i] == '0' && i + 1 < n && ip[i + 1] != '.')return false;
            else if(ip[i] >= '0' && ip[i] <= '9'){
                c = 10 * c + ip[i] - '0';
            }else{
                return false;
            }
            i++;
        }
        if(i == s)return false;
        i++;
        cnt++;
        if(c >= 0 && c <= 255)continue;
        else return false;
    }
    if(cnt == 4 && ip[n - 1] != '.')return true;
    else return false;
}

string validIPAddress(string IP) {
    int n = IP.size();
    if(n < 7)return "Neither";
    else if(n >= 7 && n < 15){
        if(isIPv4(IP))return "IPv4";
        else return "Neither";
    }else if(n > 15 && n <= 39){
        if(isIPv6(IP))return "IPv6";
        else return "Neither";
    }else{
        if(isIPv4(IP))return "IPv4";
        else if(isIPv6(IP))return "IPv6";
        else return "Neither";
    }
}

int main(){
    cout << validIPAddress("172.16.254.1") << endl;
}