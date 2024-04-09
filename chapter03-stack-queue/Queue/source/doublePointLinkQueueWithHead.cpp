/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 20:53
 * @Author Kenton
 */
#include "../head/doublePointLinkQueueWithHead.h"


void doublePointLinkQueueWithHead::InitQueue() {
    // 初始化队列 清空队列中所有元素
    LinkNode *cur = front->next;
    while (cur){
        LinkNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    front->next = nullptr;
    // 队尾指针重新指向对头
    rear = front;
}

doublePointLinkQueueWithHead::doublePointLinkQueueWithHead() {
    // 创建头结点
    front = new LinkNode(NULL);
    front->next = nullptr;
    rear = front;
}

doublePointLinkQueueWithHead::~doublePointLinkQueueWithHead() {
    LinkNode *curr = front;
    while (curr){
        LinkNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

bool doublePointLinkQueueWithHead::isEmpty() {
    return front == rear;
}

bool doublePointLinkQueueWithHead::EnQueueFront(ElemType x) {
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    newNode->next = front->next;
    front->next = newNode;
    // 如果队列为空 即插入第一个结点
    if (rear == front){
        // 更新队尾指针
        rear = newNode;
    }
    return true;
}

bool doublePointLinkQueueWithHead::EnQueueRear(ElemType x) {
   LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    rear->next = newNode;
    rear = newNode;
    return true;
}

bool doublePointLinkQueueWithHead::DeQueueFront(ElemType& x) {
    if (isEmpty()){
        return false;
    }
    LinkNode *temp = front->next;
    x = temp->data;
    front->next = temp->next;
    if (rear = temp){
        // 如果只有一个元素 更新队尾指针和队头重合
        rear = front;
    }
    delete temp;
    return true;
}

bool doublePointLinkQueueWithHead::DeQueueRear(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    LinkNode *curr = front;
    while (curr->next != rear){
        curr = curr->next;
    }
    x = curr->next->data;
    LinkNode *temp = curr->next;
    curr->next = nullptr;
    rear = curr;
    delete temp;
    return true;
}
