/**
 * @Description 静态队列 头指针初始化为0 尾指针初始化为n-1
 * @Version 1.0.0
 * @Date 2024/4/7 19:51
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICQUEUE04_H
#define INC_08WANGDAO_STATICQUEUE04_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;
};


class staticQueue04 {
public:
    SqQueue S;

    staticQueue04();

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


#endif //INC_08WANGDAO_STATICQUEUE04_H
