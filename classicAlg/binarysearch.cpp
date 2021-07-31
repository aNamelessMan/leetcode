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

// yxc的二分模板
// 找出第一个大于等于target的数
bool check1(int i, int target){
    return i >= target;
}
int bs1(const std::vector<int> &vi, int target, int l, int r){
    while(l < r){
        int mid = (l + r) / 2;
        if(check1(vi[mid], target)){// 满足条件，当然是 xx = mid，因为mid不能排除   找第一个因此右边界收缩
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}
// 找出最后一个小于等于target的数
bool check2(int i, int target){
    return i <= target;
}
int bs2(const std::vector<int> &vi, int target, int l, int r){
    while(l < r){
        int mid = (l + r + 1) / 2;  // l = mid需要向上取整，防止死循环  找最后一个，所以左边界收缩
        if(check2(vi[mid], target)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}