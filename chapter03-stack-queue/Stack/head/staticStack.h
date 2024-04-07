/**
 * @Description 栈的静态实现
 * @Version 1.0.0
 * @Date 2024/4/7 10:45
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICSTACK_H
#define INC_08WANGDAO_STATICSTACK_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct SqStack{
    // 静态数组存放栈中元素
    ElemType data[MaxSize];
    // 栈顶指针
    int top;
};


class staticStack {
public:

    SqStack S;

    // 初始化栈
    void InitStack();

    // 构造函数
    staticStack();

    // 判断栈空
    bool StackEmpty() const;

    // 新元素入栈
    bool Push(ElemType x);

    // 出栈操作 用x接收出栈的元素
    bool Pop(ElemType& x);

    // 获取栈顶元素
    bool GetTop(ElemType& x) const;

    // 判断是否满栈
    bool StackFull()const;
};


#endif //INC_08WANGDAO_STATICSTACK_H
