/**
 * @Description 静态队列 初始化头尾指针为0 用size存储长度
 * @Version 1.0.0
 * @Date 2024/4/7 17:36
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICQUEUE02_H
#define INC_08WANGDAO_STATICQUEUE02_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;
};

class staticQueue02 {
public:
    SqQueue S;

    int size;

    staticQueue02();

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


#endif //INC_08WANGDAO_STATICQUEUE02_H
