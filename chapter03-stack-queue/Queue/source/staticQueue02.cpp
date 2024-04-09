/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 17:36
 * @Author Kenton
 */
#include "../head/staticQueue02.h"

staticQueue02::staticQueue02() {
    InitQueue();
}

void staticQueue02::InitQueue() {
    S.front = S.rear = size = 0;
}

bool staticQueue02::EnQueue(ElemType x) {
    if (isFull()){
        return false;
    }
    S.data[S.rear] = x;
    S.rear = (S.rear + 1) % MaxSize;
    size++;
}

bool staticQueue02::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    x = S.data[S.front];
    S.front = (S.front + 1) % MaxSize;
    size--;
}

int staticQueue02::getSize() {
    return size;
}

bool staticQueue02::isFull() {
    return size == MaxSize;
}

bool staticQueue02::isEmpty() {
    return size == 0;
}
