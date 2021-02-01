#include <bits/stdc++.h>
using namespace std;
/*
n,m<=100000
*/
int main(){
//bfs O(m * n) = 1e10 > 1e8
//可以将树剪枝，减去没有房间的枝干
//5 / 10 个通过测试用例
    int nodeno;
    while(cin >> nodeno){
        int ssno;
        cin >> ssno;

        vector<int> a;
        a.push_back(-1);//为了让起始下标为1
        int t;
        for(int i = 0; i < nodeno; i++){
            cin >> t;
            a.push_back(t);
        }

        unordered_map<int, pair<int, int>> dp;//记录{起点， {终点， 长度}}

        int res = 0;
        for(int i = 0; i < ssno; i++){
            cin >> t;
            if(dp.find(t) != dp.end() && a[dp[t].first]){
                a[dp[t].first]--;
                res += dp[t].second;
            }else{
                unordered_set<int> tree;
                for(int i = nodeno; i > 0; i--){
                    if(a[i] || tree.find(2 * i) != tree.end() || tree.find(2 * i + 1) != tree.end()){//要么子节点在 要么本身有空间才是有效的节点
                        tree.insert(i);
                    }
                }

                //bfs;
                queue<int> q;
                unordered_set<int> processed;
                unordered_map<int, int> ceng;
                q.push(t);
                ceng.insert({t, 0});
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    if(a[cur]){
                        a[cur]--;
                        res += ceng[cur];
                        dp[t] = {cur, ceng[cur]};
                        break;
                    }else if(dp.find(cur) != dp.end() && a[dp[cur].first]){
                        a[dp[cur].first]--;
                        res += dp[cur].second + ceng[cur];
                        dp[t] = {cur, dp[cur].second + ceng[cur]};
                    }else{
                        if(cur != 1 && processed.find(cur / 2) == processed.end()){//去往父节点不需要是tree里的节点，可能是从起点往上需要经过
                            q.push(cur / 2);
                            ceng.insert({cur / 2, ceng[cur] + 1});
                        }
                        if(2 * cur <= nodeno && processed.find(cur * 2) == processed.end() && tree.find(cur * 2) != tree.end()){
                            q.push(cur * 2);
                            ceng.insert({cur * 2, ceng[cur] + 1});
                        }
                        if(2 * cur + 1 <= nodeno && processed.find(cur * 2 + 1) == processed.end() && tree.find(cur * 2 + 1) != tree.end()){
                            q.push(cur * 2 + 1);
                            ceng.insert({cur * 2 + 1, ceng[cur] + 1});
                        }
                        processed.insert(cur);
                    }
                }
            }
        }
        cout << res << endl;
    }
}