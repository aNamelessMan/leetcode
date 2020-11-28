#include "listOps.hpp"

using namespace std;

int main(){
    // ListNode *r = constructList();
    // printList(r);
    vector<int> v = {1,4,3,2,5,2};
    ListNode *s = constructList(v);
    printList(s);
}