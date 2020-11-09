#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param a: the n numbers
     * @param k: the number of integers you can choose
     * @return: how many ways that the sum of the k integers is a prime number
     */
    int getWays(vector<int> &a, int k) {
        // Write your code here
        int count=0;
        dfs(a,k,count,0,0);
        return count;
    }
    void dfs(vector<int>&a,int k,int &count,int sum,int index)
    {
        k--; 
        if(k<0) return;
        for (int i = index; i < a.size(); i++) {
            /* code */
            sum+=a[i];
            if(k==0&&isPrime(sum))count++;
            else dfs(a,k,count,sum,i+1);
            sum-=a[i];
        }
        return;
    }
    bool isPrime(int num){
        for(int i=2; i<=sqrt(num); i++)
            if(num % i == 0)
                return false;
        return true;
    }
};


int main(){
    cout << 1 << endl;
}