#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.7 MB, 在所有 C++ 提交中击败了60.76% 的用户
//虽然代码很长，但是思路很简单，就是很繁琐，要注意很多特殊用例，比如    0   10  100 1000    1000000
string numberToWords(int num) {
    if(num == 0)return "Zero";
    vector<int> n;
    int t = num;
    while(t){
        n.push_back(t % 10);
        t /= 10;
    }
    int m = n.size();
    vector<string> res;
    for(int i = 0; i < m; i++){//每三位处理一次 个十百
        if(i == 3){
            res.push_back("Thousand");
        }
        else if(i == 6){//如果前面的三位都是0，则将末尾去掉，下面同理
            if(res.back() == "Thousand")res.pop_back();
            res.push_back("Million");
        }
        else if(i == 9){
            if(res.back() == "Million")res.pop_back();
            res.push_back("Billion");
        }
        switch(n[i]){
            case 1: res.push_back("One");break;
            case 2: res.push_back("Two");break;
            case 3: res.push_back("Three");break;
            case 4: res.push_back("Four");break;
            case 5: res.push_back("Five");break;
            case 6: res.push_back("Six");break;
            case 7: res.push_back("Seven");break;
            case 8: res.push_back("Eight");break;
            case 9: res.push_back("Nine");break;
            default: break;//是0不做任何动作
        }

        i++;
        if(i == m)break;

        switch(n[i]){
            case 1: break;//如果十位是1交给后面的switch处理
            case 2: res.push_back("Twenty");break;
            case 3: res.push_back("Thirty");break;
            case 4: res.push_back("Forty");break;
            case 5: res.push_back("Fifty");break;
            case 6: res.push_back("Sixty");break;
            case 7: res.push_back("Seventy");break;
            case 8: res.push_back("Eighty");break;
            case 9: res.push_back("Ninety");break;
            default: break;
        }
        if(n[i] == 1){
            switch(n[i - 1]){
                case 1: res.pop_back();res.push_back("Eleven");break;
                case 2: res.pop_back();res.push_back("Twelve");break;
                case 3: res.pop_back();res.push_back("Thirteen");break;
                case 4: res.pop_back();res.push_back("Fourteen");break;
                case 5: res.pop_back();res.push_back("Fifteen");break;
                case 6: res.pop_back();res.push_back("Sixteen");break;
                case 7: res.pop_back();res.push_back("Seventeen");break;
                case 8: res.pop_back();res.push_back("Eighteen");break;
                case 9: res.pop_back();res.push_back("Nineteen");break;
                default: res.push_back("Ten");break;//个位是0无需去尾
            }
        }

        i++;
        if(i == m)break;
        switch(n[i]){
            case 1: res.push_back("Hundred");res.push_back("One");break;
            case 2: res.push_back("Hundred");res.push_back("Two");break;
            case 3: res.push_back("Hundred");res.push_back("Three");break;
            case 4: res.push_back("Hundred");res.push_back("Four");break;
            case 5: res.push_back("Hundred");res.push_back("Five");break;
            case 6: res.push_back("Hundred");res.push_back("Six");break;
            case 7: res.push_back("Hundred");res.push_back("Seven");break;
            case 8: res.push_back("Hundred");res.push_back("Eight");break;
            case 9: res.push_back("Hundred");res.push_back("Nine");break;
            default: break;//百位是0不用加hundred
        }
    }
    reverse(res.begin(), res.end());
    string s;
    for(auto &str:res){
        s += str;
        s += " ";
    }
    s.pop_back();
    return s;
}

int main(){
    cout << "print something." << endl;
}