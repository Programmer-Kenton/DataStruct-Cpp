/**
 * @Description 栈的链式存储 带头结点
 * @Version 1.0.0
 * @Date 2024/4/7 12:57
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_LINKSTACK_H
#define INC_08WANGDAO_LINKSTACK_H

#include "iostream"
// 链栈的最大容量
#define MaxSize 100
using ElemType = int;

struct LinkNode{
    // 数据域
    ElemType data;
    // 指针域
    struct LinkNode *next;

    LinkNode(ElemType e):data(e),next(nullptr){};
};

class LinkStack {
public:
    LinkNode *head;

    // 链栈的当前容量
    int size;

    // 初始化链栈
    void InitLinkStack();

    LinkStack();

    // 链栈进栈
    bool push_linkStack(ElemType x);

    // 链栈出栈
    bool pop_linkStack(ElemType& x);

    // 查看链栈栈顶元素
    bool GetTop(ElemType& x);

    // 链栈判空
    bool LinkStackEmpty();

    // 链栈判满
    bool LinkStackFull();

    // 析构函数
    ~LinkStack();
};


#endif //INC_08WANGDAO_LINKSTACK_H
