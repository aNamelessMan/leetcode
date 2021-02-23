#include<bits/stdc++.h>
using namespace std;

// 执行用时：108 ms, 在所有 C++ 提交中击败了76.71% 的用户
// 内存消耗：41.1 MB, 在所有 C++ 提交中击败了21.24% 的用户
//2021.2.23日二刷
class LRUCache {
private:
    int cap;
    list<pair<int,int>> l;
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
                auto iter = l.rbegin();//注意此处不能去end()再--来获取最后一个元素值，因为list迭代器是前向类型，只能取rbegin()
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
    cout << 1 << endl;
}