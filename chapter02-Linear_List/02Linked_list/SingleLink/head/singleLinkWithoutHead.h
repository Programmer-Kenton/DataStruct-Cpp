/**
 * @Description 单链表不带头结点
 * @Version 1.0.0
 * @Date 2024/3/30 13:00
 * @Author Kenton
 */

#ifndef SINGLELINKWITHOUTHEAD_H
#define SINGLELINKWITHOUTHEAD_H

#include <iostream>
using ElemType = int;

struct ListNode {
    // 数据域
    ElemType data;
    // 指针指向下一个结点
    ListNode* next;
    // 结点结构体的初始化
    ListNode(ElemType e): data(e), next(NULL) {};
};

class singleLink {
public:

    int size;

    ListNode *head;

    void InitList();

    // 不带头结点 头插法建立单链表
    bool List_TailInsert();

    // 不带头结点 头插法建立单链表
    bool List_HeadInsert();

    // 不带头结点的链表逆置
    bool List_Inverse();

    singleLink();

    ~singleLink();

    bool isEmpty();

    // 不带头结点的单链表插入操作 从1开始插入
    bool ListInsert(int i,ElemType e);

    // 不带头结点 在节点p之后插入元素e
    bool InsertNextNode(ListNode *p, ElemType e);

    // 不带头结点 在结点p之前插入元素e
    bool InsertPriorNode(ListNode *p, ElemType e);

    // 不带头结点的删除操作 删除链表中i个位置的元素 并用e返回删除元素的值
    bool ListDelete(int i,ElemType& e);

    // 不带头结点 删除指定结点 此函数有缺陷 无法删除最后一个结点 后面的双向链表结构可以解决
    bool DeleteNode(ListNode *p);

    // 不带头结点 查找指定结点的元素值
    ElemType GetElem(int i);

    // 不带头结点 查找指定位置的结点
    ListNode* GetNode(int i);

    // 不带头结点 按值查找 找到数据为e的结点
    ListNode* LocateNode(ElemType e);

    // 打印链表尺寸
    void getSize();

    // 打印不带头结点的单链表
    void printList();
};


#endif //SINGLELINKWITHOUTHEAD_H
