#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

template<typename T>
class myshared_ptr{
private:
    int* cnt;//这两个参数都是所有同一指向的只能指针共享的，当引用计数为0时，这两个数据都要销毁
    T* obj;
public:
    myshared_ptr(T* o = nullptr):obj(o){//默认构造函数
        cnt = new int(1);
    }
    myshared_ptr(const myshared_ptr& src):obj(src.obj), cnt(src.cnt{
        (*cnt)++;
    }
    myshared_ptr& operator=(const myshared_ptr& src){
        if(this != &src){//判断不是自我赋值
            cnt--;
            if(cnt == 0){
                delete cnt;
                delete obj;
            }
            cnt = src.cnt;
            obj = src.obj;
            *cnt++;
        }
        return *this;
    }
    ~myshared_ptr(){
        *cnt--;
        if(*cnt == 0){
            delete cnt;
            delete obj;
        }
    }
    T& operator*(){
        return *obj;
    }
    T* operator->(){
        return obj;
        //通用写法  return &(operator*());
    }

};

#endif