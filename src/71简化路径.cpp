#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.75% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了55.49% 的用户
typedef struct node{
    string name;
    node* parent;
}node;

string simplifyPath(string path) {
    int n = path.size();
    if(n <= 1)return path;
    node head;
    head.name = "/";
    head.parent = &head;
    node* cur = &head;

    if(path[n - 1] == '/')n--;
    for(int i = 1; i < n; i++){
        string tmp;
        while(i < n && path[i] != '/'){
            tmp += path[i];
            i++;
        }
        if(tmp == "." || tmp.empty()){

        }else if(tmp == ".."){
            cur = cur->parent;
        }else{
            node* nnode = new node;
            nnode->parent = cur;
            nnode->name = tmp;
            cur = nnode;
        }
    }
    stack<string> stk;
    while(cur->name != "/"){
        stk.push(cur->name);
        stk.push("/");
        cur = cur->parent;
    }
    if(stk.empty())return "/";
    string res;
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

int main(){
    cout << 1 << endl;
}