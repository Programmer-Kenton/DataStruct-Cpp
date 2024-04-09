/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 19:41
 * @Author Kenton
 */
#include "../head/staticQueue03.h"

staticQueue03::staticQueue03() {
    InitQueue();
    tag = 0;
}

void staticQueue03::InitQueue() {
    S.front = S.rear = 0;
}

bool staticQueue03::EnQueue(ElemType x) {
    if (isFull()){
        return false;
    }
    S.data[S.rear] = x;
    S.rear = (S.rear + 1) % MaxSize;
    tag = 1;
}

bool staticQueue03::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    x = S.data[S.front];
    S.front = (S.front + 1) % MaxSize;
    tag = 0;
}

int staticQueue03::getSize() {
    return (S.rear - S.front + MaxSize) % MaxSize;
}

bool staticQueue03::isFull() {
    return S.front == S.rear && tag == 1;
}

bool staticQueue03::isEmpty() {
    return S.front == S.rear && tag == 0;
}

