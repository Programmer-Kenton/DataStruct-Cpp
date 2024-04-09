/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 19:51
 * @Author Kenton
 */
#include "../head/staticQueue04.h"

staticQueue04::staticQueue04() {
    InitQueue();
}

void staticQueue04::InitQueue() {
    S.front = 0;
    S.rear = MaxSize - 1;
}

bool staticQueue04::EnQueue(ElemType x) {
    if (isFull()){
        return false;
    }
    S.rear = (S.rear + 1) % MaxSize;
    S.data[S.rear] = x;
    return true;
}

bool staticQueue04::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    x = S.data[S.front++];
    return true;
}

bool staticQueue04::isFull() {
    return (S.rear + 2) % MaxSize == S.front;
}

bool staticQueue04::isEmpty() {
    return S.rear == MaxSize - 1 && S.front == 0;
}
