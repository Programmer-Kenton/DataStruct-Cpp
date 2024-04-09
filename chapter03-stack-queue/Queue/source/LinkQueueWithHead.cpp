/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 20:00
 * @Author Kenton
 */
#include "../head/LinkQueueWithHead.h"

void LinkQueueWithHead::InitQueue() {
    // 创建头结点
    front = new LinkNode(0);
    // 初始化时 队尾指针指向头结点
    rear = front;
}

bool LinkQueueWithHead::isEmpty() {
    return front == rear;
}

bool LinkQueueWithHead::EnQueue(ElemType x) {
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    rear->next = newNode;
    rear = newNode;
    return true;
}

bool LinkQueueWithHead::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    LinkNode *temp = front->next;
    x = temp->data;
    front->next = temp->next;
    if (rear == temp){
        // 如果删除的是队尾结点 更新队尾指针 即链表为空 头尾重合
        rear = front;
    }
    delete temp;
    return true;
}

LinkQueueWithHead::LinkQueueWithHead() {
    InitQueue();
}

LinkQueueWithHead::~LinkQueueWithHead() {
    LinkNode *cur = front;
    while (cur){
        LinkNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    front = rear = nullptr;
}
