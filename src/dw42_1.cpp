#include<bits/stdc++.h>
using namespace std;

//找规律题，有点麻烦
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int o1 = accumulate(students.begin(),students.end(),0);
    int o2 = accumulate(sandwiches.begin(),sandwiches.end(),0);
    if(o1 == o2)return 0;
    int res = 0, n = students.size();
    if(o1 > o2){
        //那一定是被0挡住
        res = o1 - o2;//这里是两个0的数量差值
        int cnt = res;
        for(int i = n - 1; i >= 0; i--){
            if(cnt == 0)break;
            if(sandwiches[i] == 0)cnt--;
            else res++;
        }
    }else{
        //那一定是被1挡住
        res = o2 - o1;
        int cnt = res;
        for(int i = n - 1; i >= 0; i--){
            if(cnt == 0)break;
            if(sandwiches[i] == 1)cnt--;
            else res++;
        }
    }
    return res;
}

int main(){
    vector<int> students = {1, 1, 0, 0};
    vector<int> sws = {0, 1, 0, 1};

    cout << countStudents(students, sws) << endl;

    students = {1,1,1,0,0,1};
    sws = {1,0,0,0,1,1};
    cout << countStudents(students, sws) << endl;

// [0,0,0,1,0,1,1,1,1,0,1]
// [0,0,0,1,0,0,0,0,0,1,0]
    students = {0,0,0,1,0,1,1,1,1,0,1};
    sws = {0,0,0,1,0,0,0,0,0,1,0};
    cout << countStudents(students, sws) << endl;
}