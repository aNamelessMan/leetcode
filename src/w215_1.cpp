#include<bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
OrderedStream(int n) {
    strseq = vector<string>(n);
    ptr = 1;
    sz = n;
}
    
vector<string> insert(int id, string value) {
    strseq[id - 1] = value;
    vector<string> res;
    while(ptr <= sz && !strseq[ptr - 1].empty()){
        res.push_back(strseq[ptr - 1]);
        ptr++;
    }
    return res;
}
    
private:
    int sz = 0;
    int ptr = 1;
    vector<string> strseq;
};

int main(){
    cout << 1 << endl;
}