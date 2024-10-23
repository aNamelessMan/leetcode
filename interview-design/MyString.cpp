#include <bits/stdc++.h>

using namespace std;

class MyString {
public:
  MyString() : data_(nullptr), size_(0) {}
  MyString(const char *src) {}
  MyString(const MyString &src) {}
  MyString &operator=(const MyString &src) {}
  // 因为移动语义是把src的资源偷走，所以是要完成对src的修改动作的
  MyString(MyString &&src) : data_(src.data_), size_(src.size_) {
    src.data_ = nullptr;
    src.size_ = 0;
  }
  MyString &operator=(MyString &&src) {
    if (&src != this) {
      data_ = src.data_;
      size_ = src.size_;
    }
    return *this;
  }
  ~MyString() { delete[] data_; }

private:
  void init_data(const char *s) {
    data_ = new char[size_ + 1];
    memcpy(data_, s, size_);
    data_[size_ + 1] = '\0';
  }
  char *data_ = nullptr;
  int size_ = 0;
};
