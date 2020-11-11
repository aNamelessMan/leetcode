#include <vector>

int partition(std::vector<int> &A, int l, int h){
    int toset = l;
    for(int i = l; i < h; i++){
        if(A[i] < A[h]){
            std::swap(A[i], A[toset]);
            toset++;
        }
    }
    std::swap(A[toset], A[h]);
    return toset;
}

void quicksort(std::vector<int> &A, int l, int h){
    if(l < h){
        int p = partition(A, l, h);
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, h);
    }
}

void quicksort(std::vector<int> &A){
    quicksort(A, 0, A.size() - 1);
}