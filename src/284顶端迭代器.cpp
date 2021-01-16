#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了99.25% 的用户
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
    public:
    struct Data;
    Data* data;
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();
 
    // Returns true if the iteration has more elements.
    bool hasNext() const;
 };

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cur = 0;
        iter = 0;//iter要么和cur相同，要么等于cur + 1
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(cur == iter){
            cache = Iterator::next();
            iter++;
        }
        return cache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(cur == iter){
            cache = Iterator::next();
            cur++;
            iter++;
        }else{
            cur++;
        }
        return cache;
	}
	
	bool hasNext() const {
        if(cur == iter)
	        return Iterator::hasNext();
        else
            return true;
	}
private:
//分别维护底层容器和当前接口的下标，缓存前一个元素，供peek使用，cur和iter最多只会相差1且是iter-cur=1
    int cur;
    int iter;
    int cache;
};

int main(){
    cout << "print something." << endl;
}