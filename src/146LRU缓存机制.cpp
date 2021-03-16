#include<bits/stdc++.h>
using namespace std;

// 执行用时：100 ms, 在所有 C++ 提交中击败了82.44% 的用户
// 内存消耗：41 MB, 在所有 C++ 提交中击败了21.69% 的用户
//2021.3.16
class LRUCache {
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter != m.end()){
            l.push_front({key, m[key]->second});
            l.erase(m[key]);
            m[key] = l.begin();
            return l.begin()->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end()){
            l.push_front({key, value});
            l.erase(m[key]);
            m[key] = l.begin();
        }else{
            if(l.size() < cap){
                l.push_front({key, value});
                m[key] = l.begin();
            }else{
                auto iter = l.end();
                iter--;
                m.erase(m.find(iter->first));
                l.erase(iter);

                l.push_front({key, value});
                m[key] = l.begin();
            }
        }
    }
};

// 执行用时：100 ms, 在所有 C++ 提交中击败了88.02% 的用户
// 内存消耗：41.2 MB, 在所有 C++ 提交中击败了19.91% 的用户
//2021.2.23日二刷
class LRUCache {
private:
    int cap;
    list<pair<int,int>> l;//因为删除时需要获取l末尾元素的key来删除map中的值，因此不能只存value，而是存k-v对
    unordered_map<int, list<pair<int,int>>::iterator> m;//!!!!!!!!!!!!  关键是想到map中保存的是key对应的list中的位置，这样才能实现O(1)复杂度的操作
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            auto iter = m[key];
            l.insert(l.begin(), {iter->first, iter->second});
            m[key] = l.begin();
            l.erase(iter);
            return l.begin()->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            auto iter = m[key];
            l.erase(iter);
        }else{
            if(m.size() == cap){
                auto iter = l.end();
                iter--;
                auto k = iter->first;
                l.erase(m[k]);
                m.erase(m.find(k));
            }
        }
        l.insert(l.begin(), {key, value});
        m[key] = l.begin();
    }
};

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