#ifndef RAII_MUTEX_HPP
#define RAII_MUTEX_HPP

#include <pthread.h>

class Mutex{
public:
    Mutex(){
        pthread_mutex_init(&mutex, nullptr);
    }
    //禁止拷贝操作
    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;
    ~Mutex(){
        pthread_mutex_destroy(&mutex);
    }

    void lock(){
        pthread_mutex_lock(&mutex);
    }
    void unlock(){
        pthread_mutex_unlock(&mutex);
    }
private:
    pthread_mutex_t mutex;
};

class mutexGaurd{
public:
    explicit mutexGaurd(Mutex& m):mutex(m){//RAII初始化时获取资源   这里是构造时就获取互斥锁的所有权
        mutex.lock();
    };
    ~mutexGaurd(){                         //离开作用域时，编译器自动调用析构函数释放锁
        mutex.unlock();
    }

    mutexGaurd(const mutexGaurd&) = delete;
    mutexGaurd& operator= (const mutexGaurd&) = delete;

private:
    Mutex& mutex;
};

#endif