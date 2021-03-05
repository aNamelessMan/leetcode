#include <semaphore.h>
#include <pthread.h>
#include <iostream>
using namespace std;

int buffer[5];
int tail = 0;
sem_t full, empty, mutex;
void put(int x){
    buffer[tail] = x;
    tail++;
}
int get(){
    int t = buffer[tail - 1];
    tail--;
    return t;
}

void producer(){
    while(1){
        sem_wait(&empty);//尝试将已有空位数减一，没有空位则等待
        sem_wait(&mutex);//进入临界区
        put(1);
        cout << "p thread" << "f: " << tail << " e: " << 5 - tail << endl;
        sem_post(&mutex);//出临界区
        sem_post(&full);//生产完成将物品数加一
    }
}

void* customer(void*){
    while(1){
        sem_wait(&full);//尝试将已有物品数减一，没有物品则等待
        sem_wait(&mutex);
        get();
        cout << "c thread" << "f: " << tail << " e: " << 5 - tail << endl;
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(){
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);
    sem_init(&mutex, 0, 1);
    
    pthread_t t;
    int ret = pthread_create(&t, NULL, customer, NULL);
    cout << ret << endl;//为0则创建成功

    producer();

    return 0;
}