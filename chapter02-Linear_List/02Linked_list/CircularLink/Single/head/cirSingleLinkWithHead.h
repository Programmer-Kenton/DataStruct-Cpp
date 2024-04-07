/**
 * @Description 带头结点的循环单链表
 * @Version 1.0.0
 * @Date 2024/4/6 15:43
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_CIRSINGLELINKWITHHEAD_H
#define INC_08WANGDAO_CIRSINGLELINKWITHHEAD_H

#include "iostream"
using ElemType = int;

struct ListNode{
    ElemType data;

    ListNode *next;

    ListNode(ElemType e):data(e),next(nullptr){};
};

class cirSingleLinkWithHead {
    ListNode *head;

    size_t size;


    // 初始化带头结点的循环单链表
    void InitList();

    // 判断循环单链表是否为空
    bool isEmpty();

    // 判断结点p是否为带头结点循环单链表的表尾结点
    bool isTail(ListNode *p);

};


#endif //INC_08WANGDAO_CIRSINGLELINKWITHHEAD_H
