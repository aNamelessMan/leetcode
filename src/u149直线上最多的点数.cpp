#include<bits/stdc++.h>
using namespace std;

// 执行用时：60 ms, 在所有 C++ 提交中击败了50.29% 的用户
// 内存消耗：11.6 MB, 在所有 C++ 提交中击败了41.10% 的用户
int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int res = 0, n = points.size();
    for(int i = 0; i < n; i++){
        map<pair<int, int>, int> cnt;//与当前点形成的直线斜率相同的点有多少
        int dup = 0;//与当前点相同的有多少
        for(int j = 0; j < n; j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                dup++;
                continue;
            }else{
                int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                cnt[{dx, dy}]++;
            }
        }
        res = max(res, dup);//因为如果points里的点都相同，下面的循环一次都不会执行
        for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
            res = max(res, dup + iter->second);
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}