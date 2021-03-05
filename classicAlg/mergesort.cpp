#include <vector>
#include <queue>

void merge(std::vector<int> &A, int l, int mid, int h){
    int p1 = l, p2 = mid + 1;//左半段
    std::queue<int> q;
    while(p1 != mid + 1 || p2 != h + 1){
        if(p1 == mid + 1){
            q.push(A[p2]);
            p2++;
        }else if(p2 == h + 1){
            q.push(A[p1]);
            p1++;
        }else{
            if(A[p1] < A[p2]){
                q.push(A[p1]);
                p1++;
            }else{
                q.push(A[p2]);
                p2++;
            }
        }
    }
    for(int i = l; i <= h; i++){
        A[i] = q.front();
        q.pop();
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