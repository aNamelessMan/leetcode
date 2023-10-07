#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;
/*
时间 416ms
击败 90.18%使用 C++ 的用户
内存 157.99MB
击败 65.18%使用 C++ 的用户
*/
class StockPrice {
public:
    StockPrice() {}

    void update(int timestamp, int price) {
        if (stock_price.find(timestamp) != stock_price.end()) {
            int deleted_price = stock_price[timestamp];
            if (deleted_num_cnt_for_mx.find(deleted_price) !=
                deleted_num_cnt_for_mx.end()) {
                deleted_num_cnt_for_mx[deleted_price]++;
            } else {
                deleted_num_cnt_for_mx[deleted_price] = 1;
            }
            if (deleted_num_cnt_for_mn.find(deleted_price) !=
                deleted_num_cnt_for_mn.end()) {
                deleted_num_cnt_for_mn[deleted_price]++;
            } else {
                deleted_num_cnt_for_mn[deleted_price] = 1;
            }
        }
        mx.push(price);
        mn.push(price);
        stock_price[timestamp] = price;
    }

    int current() { return (stock_price.rbegin())->second; }

    int maximum() {
        int t = mx.top();
        while (deleted_num_cnt_for_mx.find(t) != deleted_num_cnt_for_mx.end() &&
               deleted_num_cnt_for_mx[t]) {
            deleted_num_cnt_for_mx[t]--;
            mx.pop();
            t = mx.top();
        }
        return t;
    }

    int minimum() {
        int t = mn.top();
        while (deleted_num_cnt_for_mn.find(t) != deleted_num_cnt_for_mn.end() &&
               deleted_num_cnt_for_mn[t]) {
            deleted_num_cnt_for_mn[t]--;
            mn.pop();
            t = mn.top();
        }
        return t;
    }

private:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    unordered_map<int, int> deleted_num_cnt_for_mx;
    unordered_map<int, int> deleted_num_cnt_for_mn;
    map<int, int> stock_price;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main() {
    StockPrice* obj = new StockPrice();
    obj->update(1, 10);
    obj->update(2, 5);
    cout << obj->current() << endl;
    cout << obj->maximum() << endl;
    obj->update(1, 3);
    cout << obj->maximum() << endl;
    obj->update(4, 2);
    cout << obj->minimum() << endl;
}
