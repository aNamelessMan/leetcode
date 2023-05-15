//
// Created by 秦俊 on 2023/5/15.
//

#include <iostream>
#include <string>
//构造函数中抛出异常，不会调用该类的析构函数，只会逐个调用其data member的析构函数
class bar
{
public:
    bar(std::string name) : name_(name)
    {
        std::cout << name_ << ": bar() called" << std::endl;
    }

    ~bar()
    {
        std::cout << name_ << ": ~bar() called" << std::endl;
    }
private:
    std::string name_;
};
class foo
{
public:
    foo()
            : b(new bar("pointer_b")), b1("b1")
    {
        std::cout << "foo() called" << std::endl;
        throw "throw something";
        b2 = bar("b2");
    }

    ~foo()
    {
        delete b;
        std::cout << "~foo() called" << std::endl;
    }

private:
    bar *b;
    bar b1;
    bar b2 = bar("uninit");
};


int main(void)
{
    try {
        std::cout << "heap: new foo" << std::endl;
        foo *f = new foo();
    } catch (const char *e) {
        std::cout << "heap exception: " << e << std::endl;
    }

    try {
        std::cout << "stack: foo" << std::endl;
        foo f;
    } catch (const char *e) {
        std::cout << "stack exception: " << e << std::endl;
    }

    return 0;
}
/** out
heap: new foo
pointer_b: bar() called
b1: bar() called
uninit: bar() called
foo() called
uninit: ~bar() called
b1: ~bar() called
heap exception: throw something
stack: foo
pointer_b: bar() called
b1: bar() called
uninit: bar() called
foo() called
uninit: ~bar() called
b1: ~bar() called
stack exception: throw something
*/

