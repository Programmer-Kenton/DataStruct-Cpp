/**
 * @Description 带头结点链式存储实现双端队列
 * @Version 1.0.0
 * @Date 2024/4/7 20:53
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHHEAD_H
#define INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHHEAD_H

#include "iostream"
using ElemType = int;

struct LinkNode{
    ElemType data;

    struct LinkNode *next;

    LinkNode(ElemType e):data(e),next(nullptr){}
};


class doublePointLinkQueueWithHead {
public:
    // 队头队尾指针
    LinkNode *front,*rear;

    void InitQueue();

    doublePointLinkQueueWithHead();

    ~doublePointLinkQueueWithHead();

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


#endif //INC_08WANGDAO_DOUBLEPOINTLINKQUEUEWITHHEAD_H
