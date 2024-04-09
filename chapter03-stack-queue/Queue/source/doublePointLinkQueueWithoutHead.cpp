/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 21:43
 * @Author Kenton
 */
#include "../head/doublePointLinkQueueWithoutHead.h"

doublePointLinkQueueWithoutHead::doublePointLinkQueueWithoutHead() {
    // 不带头结点 初始化队头队尾指针为空
    front = rear = nullptr;
}

doublePointLinkQueueWithoutHead::~doublePointLinkQueueWithoutHead() {
    LinkNode *curr = front;
    while (curr){
        LinkNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    front = rear = nullptr;
}

void doublePointLinkQueueWithoutHead::InitQueue() {
    // 初始化列表 清空列队所有元素
    LinkNode *curr = front;
    while (curr){
        LinkNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    front = rear = nullptr;
}

bool doublePointLinkQueueWithoutHead::isEmpty() {
    return front == rear;
}

bool doublePointLinkQueueWithoutHead::EnQueueFront(ElemType x) {
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    newNode->next = front;
    front = newNode;
    if (rear == nullptr){
        // 队列为空
        rear = newNode;
    }
    return true;
}

bool doublePointLinkQueueWithoutHead::EnQueueRear(ElemType x) {
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        return false;
    }
    // 不是第一个结点
    if (rear){
        rear->next = newNode;
    } else{
        front = newNode;
    }
    rear = newNode;
    return true;
}

bool doublePointLinkQueueWithoutHead::DeQueueFront(ElemType &x) {
    // 从队头删除元素
    if (isEmpty()) {
        return false;
    }
    LinkNode *temp = front;
    x = temp->data;
    front = temp->next;
    if (front == nullptr) {
        rear = nullptr; // 如果队列中只有一个元素，删除后队尾指针也为nullptr
    }
    delete temp;
    return true;
}

bool doublePointLinkQueueWithoutHead::DeQueueRear(ElemType &x) {
    if (isEmpty()){
        return false;
    }
    // 队列中只有一个元素
    if (front == rear){
        x = rear->data;
        LinkNode *temp = rear;
        front = rear = nullptr;
        delete temp;
    } else{
        LinkNode *curr = front;
        while (curr->next != rear){
            curr = curr->next;
        }
        x = curr->next->data; // x = rear->data
        LinkNode *temp = rear;
        rear = curr;
        rear->next = nullptr;
        delete temp;
    }
    return true;
}
