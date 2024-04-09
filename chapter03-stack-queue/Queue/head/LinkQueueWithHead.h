/**
 * @Description 链式队列 带头结点
 * @Version 1.0.0
 * @Date 2024/4/7 20:00
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_LINKQUEUEWITHHEAD_H
#define INC_08WANGDAO_LINKQUEUEWITHHEAD_H

#include "iostream"
using ElemType = int;

struct LinkNode{
    ElemType data;

    struct LinkNode *next;

    LinkNode(ElemType e):data(e),next(nullptr){}
};

class LinkQueueWithHead {
public:
    // 队列头尾指针
    LinkNode *front,*rear;

    LinkQueueWithHead();

    ~LinkQueueWithHead();

    // 初始化队列
    void InitQueue();

    bool isEmpty();

    bool EnQueue(ElemType x);

    bool DeQueue(ElemType& x);
};


#endif //INC_08WANGDAO_LINKQUEUEWITHHEAD_H
