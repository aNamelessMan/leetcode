#include <bits/stdc++.h>
using namespace std;

int divisor(int a, int b) {
	int temp;
	//比较两个数的大小，值大的数为a，值小的数为b
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int solution(vector<int> &X, vector<int> &Y) {
    // write your code in C++14 (g++ 6.2.0)
    //两个分子和为分母
    long long res = 0;
    unordered_map<int, unordered_map<int, int>> m;//以分母为索引
    int tn = 0;
    int n = X.size();
    for(int i = 0; i < n; i++){
        int s = divisor(X[i], Y[i]);
        X[i] /= s;
        Y[i] /= s;
        if(2 * X[i] == Y[i])tn++;
        else m[X[i]][Y[i]]++;
    }
    for(auto &p:m){
        int sum = p.first;//分母
        for(auto &d:p.second){
            res += d.second * p.second[sum - d.first];
        }
    }
    res /= 2;
    res += (tn - 1) * tn / 2;
    return res % int(1e9 + 7);
}

int main(){
    vector<int> X{1, 1, 2};
    vector<int> Y{3, 2, 3};
    solution(X, Y);
    cout << "print sth." << endl;
}