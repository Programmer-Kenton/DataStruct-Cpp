/**
 * @Description 带头结点的双向链表
 * @Version 1.0.0
 * @Date 2024/4/2 11:41
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_DOUBLELINKWITHHEAD_H
#define INC_08WANGDAO_DOUBLELINKWITHHEAD_H

#include <iostream>
using EleType = int;

struct ListDNode{
    EleType data;

    ListDNode *next;

    ListDNode *prior;

    ListDNode(EleType e): data(e), next(nullptr), prior(nullptr){}
};


class doubleLinkWithHead {

public:

    ListDNode *head;

    int size;

    // 初始化双向链表
    void InitDLinkList();

    // 构造函数
    doubleLinkWithHead();

    // 析构函数
    ~doubleLinkWithHead();

    // 判断双向链表是否为空
    bool isEmpty();

    // 在p结点之后插入s结点
    bool InsertNextDNode(ListDNode *p,ListDNode *s);

    // 在p结点之前插入s结点
    bool InsertPriorDNode(ListDNode *p,ListDNode *s);

    // 删除p结点后续结点
    bool DeleteNextDNode(ListDNode *p);

    // 打印双向链表
    void printList();
};


#endif //INC_08WANGDAO_DOUBLELINKWITHHEAD_H
