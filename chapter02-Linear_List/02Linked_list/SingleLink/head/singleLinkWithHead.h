/**
 * @Description 带头结点的单链表
 * @Version 1.0.0
 * @Date 2024/3/30 12:38
 * @Author Kenton
 */

#ifndef SINGLELINK_H
#define SINGLELINK_H

#include <iostream>
using ElemType = int;

struct ListNode {
    // 数据域
    ElemType data;
    // 指针指向下一个结点
    ListNode *next;
    // 结点结构体的初始化
    ListNode(ElemType e): data(e), next(NULL){};
};

class singleLink {
public:
    ListNode *head;

    int size;

    // 初始化单链表
    void InitList();

    // 判断单链表是否为空
    bool isEmpty();

    // 构造函数
    singleLink();

    // 析构函数 释放链表占用的空间
    ~singleLink();

    // 带头结点 尾插法建立单链表
    bool List_TailInsert();

    // 带头结点 头插法建立单链表
    bool List_HeadInsert();

    // 带头结点的链表逆置
    bool List_Inverse();

    // 在带头结点的链表第i个位置插入元素e 这里的i从1开始
    bool ListInsert(int i,ElemType e);

    // 带头结点 在p结点之后插入元素e 后插
    bool InsertNextNode(ListNode *p, ElemType e);

    // 在p结点之前插入元素 e 前插
    bool InsertPriorNode(ListNode *p, ElemType e);

    // 带头结点的删除操作 删除链表中i个位置的元素 并用e返回删除元素的值
    bool ListDelete(int i,ElemType& e);

    // 删除指定结点 此函数有缺陷 无法删除最后一个结点 后面的双向链表结构可以解决
    bool DeleteNode(ListNode *p);

    // 带头结点 查找指定结点的元素值
    ElemType GetElem(int i);

    // 带头结点 按位查找 返回第i个位置的结点
    ListNode* GetNode(int i);

    // 带头结点 按值查找 找到数据为e的结点
    ListNode* LocateNode(ElemType e);

    // 打印链表尺寸
    void getSize();

    // 打印链表中的元素
    void printList();

    // 以下是LeetCode要用到的接口

    // 数列求和
    ElemType Sum();

    // 数列末尾插值
    void append(ElemType e);

    // 递增顺序插入
    void ascInsert(ElemType e);
};


#endif //SINGLELINK_H
