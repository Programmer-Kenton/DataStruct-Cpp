/**
 * @Description 不带头结点链式存储实现双端队列
 * @Version 1.0.0
 * @Date 2024/4/7 21:43
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHOUTHEAD_H
#define INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHOUTHEAD_H

#include "iostream"
using ElemType = int;

struct LinkNode{
    ElemType data;

    struct LinkNode *next;

    LinkNode(ElemType e):data(e),next(nullptr){}
};


class doublePointLinkQueueWithoutHead {
public:
    // 队头队尾指针
    LinkNode *front,*rear;

    void InitQueue();

    doublePointLinkQueueWithoutHead();

    ~doublePointLinkQueueWithoutHead();

    bool isEmpty();

    // 队头插入
    bool EnQueueFront(ElemType x);

    // 队尾插入
    bool EnQueueRear(ElemType x);

    // 队头删除
    bool DeQueueFront(ElemType& x);

    // 队尾删除
    bool DeQueueRear(ElemType& x);
};


#endif //INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHOUTHEAD_H
