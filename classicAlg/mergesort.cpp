#include <vector>
#include <queue>

void merge(std::vector<int> &A, int l, int mid, int h){
    std::queue<int> q1;
    for(int i = l; i <= mid; i++){
        q1.push(A[i]);
    }
    std::queue<int> q2;
    for(int i = mid + 1; i <= h; i++){
        q2.push(A[i]);
    }
    for(int i = l; i <= h; i++){
        if(q1.empty()){
            A[i] = q2.front();
            q2.pop();
        }else if (q2.empty()){
            A[i] = q1.front();
            q1.pop();
        }else{
            if(q1.front() < q2.front()){
                A[i] = q1.front();
                q1.pop();
            }else{
                A[i] = q2.front();
                q2.pop();
            }
        }
    }
}

void mergesort(std::vector<int> &A, int l, int h){
    if(l < h){
        int mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void mergesort(std::vector<int> &A){
    mergesort(A, 0, A.size() - 1);
}