#include<bits/stdc++.h>
using namespace std;

// 2023 618再刷
class FooLRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto i = m.find(key);
        if(i == m.end()){
            return -1;
        }else{
            auto p = i->second;
            pair<int, int> t = *p;
            l.erase(p);
            l.push_back(t);
            m[key] = (--l.end());
            return l.rbegin()->second;
        }
    }
    
    void put(int key, int value) {
        auto i = m.find(key);
        if(i != m.end()){
            auto p = i->second;
            pair<int, int> t{key, value};
            l.erase(p);
            l.push_back(t);
            m[key] = (--l.end());
        }else{
            if(l.size() == cap){
                m.erase(m.find(l.begin()->first));
                l.erase(l.begin());
            }
            pair<int, int> p(key, value);
            l.push_back(p);
            m[key] = (--l.end());
        }
    }
private:
    size_t cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
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

int main(){
    LRUCache lru =  LRUCache(2);
    lru.put(1, 0);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
}