#ifndef SINGLETON_HPP
#define SINGLETON_HPP

class A{
public:
    static A& getInstance(){
        static A a;//这里的a就是普通的静态变量，不是A的静态数据成员
        return a;
    }
    void setup(){}//修改a
private://将构造函数和拷贝构造函数设为private，即可禁止用户构造A类对象
    A();
    A(const A& rhs);
};

#endif

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     A::getInstance();
// }