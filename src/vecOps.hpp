#ifndef VEC_OPS_HPP
#define VEC_OPS_HPP

#include <iostream>
#include <vector>

void printVector(std::vector<int> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

void printVecOfVec(std::vector<std::vector<int>> v){
    int n = v.size();
    for(int i = 0; i < n; i++)
        printVector(v[i]);
}

#endif