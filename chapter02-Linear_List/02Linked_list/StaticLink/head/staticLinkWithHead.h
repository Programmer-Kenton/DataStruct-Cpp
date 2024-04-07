/**
 * @Description TODO带头结点的静态链表
 * @Version 1.0.0
 * @Date 2024/4/6 16:06
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICLINKWITHHEAD_H
#define INC_08WANGDAO_STATICLINKWITHHEAD_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct Node{
    // 存储数据元素
    ElemType data;
    // 下一个元素的数组坐标
    int next;
};

class staticLinkWithHead {
public:

    // 静态链表空间
    Node space[MaxSize];

    // 头结点指针
    Node *head;

    // 指向第一个空闲结点的指针
    int free;

    // 初始化静态链表
    void InitList();

    // 构造函数
    staticLinkWithHead();

    // 在静态链表中数组坐标为i的位置插入新元素e
    bool ListInsert(int i,ElemType e);

    // 删除静态链表中数组坐标位置为i的元素
    bool ListDelete(int i);

    // 打印静态链表
    void printList();

};


#endif //INC_08WANGDAO_STATICLINKWITHHEAD_H
