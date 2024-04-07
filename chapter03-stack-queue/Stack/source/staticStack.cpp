/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 10:45
 * @Author Kenton
 */

#include "../head/staticStack.h"

staticStack::staticStack() {
    InitStack();
}

void staticStack::InitStack() {
    // 初始栈定指针为-1 表示空栈
    S.top = -1;
}

bool staticStack::StackEmpty() const {
    return S.top == -1;
}

bool staticStack::Push(ElemType x) {
    // 栈满 无法入栈
    if (StackFull()){
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool staticStack::Pop(ElemType &x) {
    if (StackEmpty()){
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool staticStack::GetTop(ElemType &x) const{
    if (StackEmpty()){
        return false;
    }
    x = S.data[S.top];
    return true;
}

bool staticStack::StackFull() const {
    return S.top == MaxSize - 1;
}
