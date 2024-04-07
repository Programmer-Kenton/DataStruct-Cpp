/**
 * @Description 静态队列
 * @Version 1.0.0
 * @Date 2024/4/7 17:01
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICQUEUE_H
#define INC_08WANGDAO_STATICQUEUE_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;
};

class staticQueue {
public:
    SqQueue S;

    int size;

    staticQueue();

    ~staticQueue();

    // 初始化队列
    void InitQueue();

    // 入队
    bool EnQueue(ElemType x);



};


#endif //INC_08WANGDAO_STATICQUEUE_H
