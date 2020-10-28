#include<bits/stdc++.h>
using namespace std;
// 执行用时：168 ms, 在所有 C++ 提交中击败了98.11% 的用户
// 内存消耗：40.8 MB, 在所有 C++ 提交中击败了12.67% 的用户
//private:
int cap;
list<pair<int,int>> l;
unordered_map<int, list<pair<int,int>>::iterator> m;//保存int对应的list中的位置
//public:
void LRUCache(int capacity) {
    cap = capacity;
}
    
int get(int key) {//除了返回值以外，还要将该k-v对放到l最前方，以便于删除
    auto i = m.find(key);
    if(i == m.end())return -1;
    l.splice(l.begin(), l, i->second);
    return i->second->second;
}
    
void put(int key, int value) {
    auto i = m.find(key);
    if(i != m.end())l.erase(i->second);

    if(l.size() == cap){//题解有点问题，应该放在添加之前才能满足不超过上限，在写入前删除
        auto k = l.rbegin()->first;
        m.erase(k);
        l.pop_back();
    }

    l.push_front(make_pair(key, value));
    m[key] = l.begin();
}

int main(){
    cout << 1 << endl;
}