/**
 * @Description 静态队列 初始化头尾指针位置为0 无size和tag
 * @Version 1.0.0
 * @Date 2024/4/7 17:01
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICQUEUE_H
#define INC_08WANGDAO_STATICQUEUE_H

#include "iostream"
#define defaultNum 10
using ElemType = int;

struct SqQueue{
    ElemType data[defaultNum];
    int front,rear;
};

class staticQueue {
public:
    SqQueue S;

    staticQueue();

    // 初始化队列
    void InitQueue();

    // 入队
    bool EnQueue(ElemType x);

    // 出队
    bool DeQueue(ElemType& x);

    // 队列元素个数
    int getSize();

    // 判断队满
    bool isFull();

    // 判断队空
    bool isEmpty();
};


#endif //INC_08WANGDAO_STATICQUEUE_H
