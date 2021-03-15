#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, r;
    while(cin >> n >> r){
        vector<int> zuxian(n);
        zuxian[0] = -1;
        int t, s;
        cin >> s;
        vector<int> zhim;
        unordered_set<int> zz;
        for(int i = 0; i < s; i++){
            cin >> t;
            zhim.push_back(t);
            zz.insert(t);
        }
        
        for(int i = 0; i < r; i++){
            int p;
            cin >> p;
            cin >> s;
            for(int j = 0; j < s; j++){
                cin >> t;
                zuxian[t] = p;
            }
        }
        
        vector<vector<int>> path;
        int mns = INT_MAX;
        for(int i = 0; i < int(zhim.size()); i++){
            path.push_back({});
            int cur = zhim[i];
            //path.back().push_back(cur);
            while(cur != -1){
                path.back().push_back(cur);
                cur = zuxian[cur];
                //path.back().push_back(cur);
            }
            reverse(path.back().begin(), path.back().end());
            mns = min(mns, int(path.back().size()));
        }
        
        int i;
        bool jieshu = false;
        for(i = 0; i < mns; i++){
            int s = path[0][i];
            for(auto &p:path){
                if(p[i] != s){
                    jieshu = true;
                    break;
                }
            }
            if(jieshu)break;
        }
        if(zz.find(path[0][i - 1]) == zz.end())
            cout << path[0][i - 1] << endl;
        else 
            cout << zuxian[path[0][i - 1]] << endl;
    }
}