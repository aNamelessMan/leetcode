#ifndef VEC_OPS_HPP
#define VEC_OPS_HPP

#include <iostream>
#include <vector>

template<typename T>
void printVector(const std::vector<T> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
void printVecOfVec(const std::vector<std::vector<T>> &v){
    int n = v.size();
    for(int i = 0; i < n; i++)
        printVector(v[i]);
}

#endif