/**
 * @Description 带头结点的循环双链表
 * @Version 1.0.0
 * @Date 2024/4/6 15:52
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_CIRDOUBLELINKWITHHEAD_H
#define INC_08WANGDAO_CIRDOUBLELINKWITHHEAD_H

#include <iostream>
using EleType = int;

struct ListDNode{
    EleType data;

    ListDNode *next;

    ListDNode *prior;

    ListDNode(EleType e): data(e), next(nullptr), prior(nullptr){}
};

class cirDoubleLinkWithHead {

    // 初始化空的循环双链表
    void InitDLinkList();

    // 判断循环双链表是否为空
    bool isEmpty();

    // 判断结点p是否为循环双链表的表尾结点
    bool isTail(ListDNode *p);

    // 在p结点之后插入s结点
    bool InsertNextDNode(ListDNode *p,ListDNode *s);

    // 删除p的后继结点
    bool DeleteNextDNode(ListDNode *p);
};


#endif //INC_08WANGDAO_CIRDOUBLELINKWITHHEAD_H
