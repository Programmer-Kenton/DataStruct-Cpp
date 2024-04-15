/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 12:57
 * @Author Kenton
 */
#include "../head/LinkStack.h"

void LinkStack::InitLinkStack() {
    // 创建头结点 不存储数据
    head = new LinkNode(NULL);
    if (!head){
        std::cerr << "Memory allocation failed to head node!" << std::endl;
        exit(1);
    }
    size = 0;
}

LinkStack::LinkStack() {
    InitLinkStack();
}

bool LinkStack::push_linkStack(ElemType x) {
    if (LinkStackFull()){
        // 栈满 无法进栈
        std::cerr << "Stack is full,can't push element" << std::endl;
        return false;
    }
    LinkNode *newNode = new LinkNode(x);
    if (!newNode){
        std::cerr << "Memory allocation failed to new node!" << std::endl;
        exit(1);
    }
    newNode->next = head->next;
    head->next = newNode;
    size++;
    return true;
}

bool LinkStack::pop_linkStack(ElemType &x) {
    if (LinkStackEmpty()){
        std::cerr << "Stack is empty,can't pop element" << std::endl;
        return false;
    }
    LinkNode *p = head->next;
    // 取出栈顶元素
    x = p->data;
    head->next = p->next;
    // 释放栈顶元素的空间
    delete p;
    size--;
    return true;
}

bool LinkStack::GetTop(ElemType &x) {
    if (LinkStackEmpty()){
        std::cerr << "Stack is empty, cannot get top element!" << std::endl;
        return false;
    }
    x = head->next->data;
    return true;
}

bool LinkStack::LinkStackEmpty() {
    return head->next == nullptr;
}

bool LinkStack::LinkStackFull() {
    return size == defaultNum;
}

LinkStack::~LinkStack() {
    LinkNode *curr = head;
    LinkNode *prev = nullptr;
    while (curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    head = nullptr;
}

