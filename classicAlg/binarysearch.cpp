#include <vector>


int binarysearch(std::vector<int> &A, int target, int l, int h){
    if(h < l)return -1;
    int mid = (h + l) / 2;
    if(A[mid] == target)return mid;
    if(A[mid] < target)return binarysearch(A, target, mid + 1, h);
    else return binarysearch(A, target, l, mid - 1);
}

int binarysearch(std::vector<int> &A, int target){
    return binarysearch(A, target, 0, A.size() - 1);
}