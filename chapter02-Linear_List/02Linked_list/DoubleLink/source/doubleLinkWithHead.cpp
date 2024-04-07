/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/2 11:41
 * @Author Kenton
 */
#include "../head/doubleLinkWithHead.h"

void doubleLinkWithHead::InitDLinkList() {
    // 创建头结点
    head = new ListDNode(0);
    size = 0;
}

doubleLinkWithHead::doubleLinkWithHead() {
    // 初始化双向链表
    InitDLinkList();
}

doubleLinkWithHead::~doubleLinkWithHead() {
    // 清除链表
    ListDNode *cur = head->next;
    while (cur != nullptr){
        ListDNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    // 删除头结点
    delete head;
}

bool doubleLinkWithHead::isEmpty() {
    return size == 0;
}

bool doubleLinkWithHead::InsertNextDNode(ListDNode *p, ListDNode *s) {
    if (p == nullptr || s == nullptr){
        // p或s为空 插入失败
        return false;
    }
    s->next = p->next;
    // 如果p不是最后一个结点
    if (p->next != nullptr){
        p->next->prior = s;
    }
    p->next = s;
    s->prior = p;
    size++;
    return true;
}

bool doubleLinkWithHead::InsertPriorDNode(ListDNode *p, ListDNode *s) {
    if (p == nullptr || s == nullptr){
        // p或s为空 插入失败
        return false;
    }
    s->prior = p->prior;
    // 如果p之前的结点不为空
    if (p->prior != nullptr){
        p->prior->next = s;
    }
    p->prior = s;
    s->next = p;
    size++;
    return true;
}

bool doubleLinkWithHead::DeleteNextDNode(ListDNode *p) {
    if (p == nullptr || p->next == nullptr){
        // p为空或p没有后续结点 删除失败
        return false;
    }
    ListDNode *temp = p->next;
    p->next = temp->next;
    if (temp->next != nullptr){
        temp->next->prior = p;
    }
    delete temp;
    size--;
    return true;
}

void doubleLinkWithHead::printList() {
    ListDNode *cur = head->next;
    while (cur != nullptr){
        std::cout << cur->data << ' ';
        cur = cur->next;
    }
    std::cout << std::endl;
}
