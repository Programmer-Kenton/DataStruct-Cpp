/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 22:31
 * @Author Kenton
 */
#include "../head/doublePointStaticQueue.h"

doublePointStaticQueue::doublePointStaticQueue() {
    InitQueue();
}

void doublePointStaticQueue::InitQueue() {
    Q.front = Q.rear = -1;
}

bool doublePointStaticQueue::EnQueueRear(const ElemType &e) {
    if (isFull()){
        return false;
    }
    Q.data[++Q.rear] = e;
    return true;
}

bool doublePointStaticQueue::EnQueueFront(const ElemType &e) {
    if (isFull()){
        return false;
    }
    if (Q.front == -1){
        // 原队列为空 队首指向数组起始位置
        Q.front = 0;
    } else{
        // 队首指针向前移动
        Q.front = (Q.front - 1 + MaxSize) % MaxSize;
    }
    Q.data[Q.front] = e;
    return true;
}

bool doublePointStaticQueue::DeQueueRear(ElemType &e) {
    if (isEmpty()){
        return false;
    }
    e = Q.data[Q.rear--];
    return true;
}

bool doublePointStaticQueue::DeQueueFront(ElemType &e) {
    if (isEmpty()){
        return false;
    }
    e = Q.data[Q.front++];
    if (Q.front == MaxSize){
        Q.front = 0;
    }
    return true;
}

void doublePointStaticQueue::printQueue() {
    if (isEmpty()){
        return;
    }
    for (int i = Q.front;i != Q.rear;i = (i + 1) % MaxSize) {
        std::cout << Q.data[i] << ' ';
    }
    std::cout << std::endl;
}

int doublePointStaticQueue::getSize() {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

bool doublePointStaticQueue::isFull() {
    return (Q.rear + 1) % MaxSize == Q.front;
}

bool doublePointStaticQueue::isEmpty() {
    return Q.front == -1;
}


