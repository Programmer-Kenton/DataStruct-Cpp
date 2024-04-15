/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 17:01
 * @Author Kenton
 */

#include "../head/staticQueue.h"

staticQueue::staticQueue() {
    InitQueue();
}

void staticQueue::InitQueue() {
    // 初始化队头队尾指针
    S.front = S.rear = 0;
}

bool staticQueue::EnQueue(ElemType x) {
    if (isFull()){
        return false;
    }
    S.data[S.rear] = x;
    S.rear = (S.rear + 1) % defaultNum;
    return true;
}

bool staticQueue::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    x = S.data[S.front];
    S.front = (S.front + 1) % defaultNum;
    return true;
}

int staticQueue::getSize() {
    return (S.rear - S.front + defaultNum) % defaultNum;
}

bool staticQueue::isFull() {
    return (S.rear + 1) % defaultNum == S.front;
}

bool staticQueue::isEmpty() {
    return S.front == S.rear;
}
