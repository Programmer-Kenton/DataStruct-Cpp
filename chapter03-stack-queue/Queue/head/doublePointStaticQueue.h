/**
 * @Description 静态双端队列
 * @Version 1.0.0
 * @Date 2024/4/7 22:31
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DOUBLEPOINTSTATICQUEUE_H
#define INC_08WANGDAO_DOUBLEPOINTSTATICQUEUE_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;
};

class doublePointStaticQueue {
public:
    SqQueue Q;

    doublePointStaticQueue();

    // 初始化队列
    void InitQueue();

    bool EnQueueRear(const ElemType& e);

    bool EnQueueFront(const ElemType& e);

    bool DeQueueRear(ElemType& e);

    bool DeQueueFront(ElemType& e);

    void printQueue();

    // 队列元素个数
    int getSize();

    // 判断队满
    bool isFull();

    // 判断队空
    bool isEmpty();
};


#endif //INC_08WANGDAO_DOUBLEPOINTSTATICQUEUE_H
