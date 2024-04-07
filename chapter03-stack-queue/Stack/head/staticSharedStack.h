/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 11:21
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_STATICSHAREDSTACK_H
#define INC_08WANGDAO_STATICSHAREDSTACK_H

#include "iostream"
#define MaxSize 10
using ElemType = int;

struct ShStack{
    // 静态数组存放栈中元素
    ElemType data[MaxSize];
    // 0号栈顶指针
    int top0;
    // 1号栈顶指针
    int top1;
};


class staticSharedStack {
public:
    ShStack S;

    // 初始化共享栈
    void InitStack();

    // 构造函数
    staticSharedStack();

    // 判断共享栈栈空
    bool StackEmpty() const;

    // 新元素入栈0
    bool Push0(ElemType x);

    // 新元素入栈1
    bool Push1(ElemType x);

    // 出栈操作 用x接收出栈0的元素
    bool Pop0(ElemType& x);

    // 出栈操作 用x接收出栈1的元素
    bool Pop1(ElemType& x);

    // 获取栈0的栈顶元素
    bool GetTop0(ElemType& x) const;

    // 获取栈1的栈顶元素
    bool GetTop1(ElemType& x) const;

    // 判断共享栈是否满栈
    bool StackFull()const;
};


#endif //INC_08WANGDAO_STATICSHAREDSTACK_H
