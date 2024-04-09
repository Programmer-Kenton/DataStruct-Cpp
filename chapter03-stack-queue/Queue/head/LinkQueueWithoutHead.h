/**
 * @Description 不带头结点的链式队列
 * @Version 1.0.0
 * @Date 2024/4/7 20:11
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_LINKQUEUEWITHOUTHEAD_H
#define INC_08WANGDAO_LINKQUEUEWITHOUTHEAD_H

#include "iostream"
using ElemType = int;

struct LinkNode{
    ElemType data;

    struct LinkNode *next;

    LinkNode(ElemType e):data(e),next(nullptr){}
};

class LinkQueueWithoutHead {
public:
    // 队列头尾指针
    LinkNode *front,*rear;

    LinkQueueWithoutHead();

    ~LinkQueueWithoutHead();

    // 初始化队列
    void InitQueue();

    bool isEmpty();

    bool EnQueue(ElemType x);

    bool DeQueue(ElemType& x);
};


#endif //INC_08WANGDAO_LINKQUEUEWITHOUTHEAD_H
