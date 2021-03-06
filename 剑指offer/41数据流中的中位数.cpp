#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> bq;
    priority_queue<int> sq;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(bq.size() == sq.size()){
            bq.push(num);
        }else{
            sq.push(-num);
        }
        if(!bq.empty() && !sq.empty() && bq.top() > -sq.top()){//记得判断不为空
            int v1 = bq.top(), v2 = sq.top();
            bq.pop();
            sq.pop();
            bq.push(-v2);
            sq.push(-v1);

        }
    }
    
    double findMedian() {
        if(bq.size() == sq.size())return (double(bq.top()) - sq.top()) / 2;
        else return bq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    cout << "print sth." << endl;
}