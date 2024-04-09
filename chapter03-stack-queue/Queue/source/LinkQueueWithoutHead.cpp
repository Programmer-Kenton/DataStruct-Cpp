/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 20:11
 * @Author Kenton
 */

#include "../head/LinkQueueWithoutHead.h"

void LinkQueueWithoutHead::InitQueue() {
    // 初始化 头为节点均为空
    front = rear = nullptr;
}

LinkQueueWithoutHead::~LinkQueueWithoutHead() {
    LinkNode *curr = front;
    while (curr){
        LinkNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    front = rear = nullptr;
}

LinkQueueWithoutHead::LinkQueueWithoutHead() {
    InitQueue();
}

bool LinkQueueWithoutHead::isEmpty() {
    return front == rear;
}

bool LinkQueueWithoutHead::EnQueue(ElemType x) {
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    if (rear){
        rear ->next = newNode;
    } else{
        // 空队列第一个结点
        front = newNode;
    }
    rear = newNode;
    return true;
}

bool LinkQueueWithoutHead::DeQueue(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    LinkNode *temp = front;
    x = temp->data;
    front = temp->next;
    if (front == rear){
        // 如果删除唯一结点
        rear = nullptr;
    }
    delete temp;
    return true;
}
