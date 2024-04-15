/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 11:21
 * @Author Kenton
 */
#include "../head/staticSharedStack.h"

staticSharedStack::staticSharedStack() {
    InitStack();
}

void staticSharedStack::InitStack() {
    // 初始化0号栈顶指针
    S.top0 = -1;
    // 初始化1号栈顶指针
    S.top1 = defaultNum;
}

bool staticSharedStack::StackEmpty() const {
    return S.top1 == -1 && S.top1 == defaultNum;
}

bool staticSharedStack::StackFull() const {
    return S.top0 + 1 == S.top1;
}

bool staticSharedStack::Push0(ElemType x) {
    if (StackFull()){
        // 共享栈满
        return false;
    }
    S.data[++S.top0] = x;
    return true;
}

bool staticSharedStack::Push1(ElemType x) {
    if (StackFull()){
        return false;
    }
    S.data[--S.top1] = x;
    return true;
}

bool staticSharedStack::Pop0(ElemType &x) {
    if (S.top0 == -1){
        return false;
    }
    x = S.data[S.top0--];
    return true;
}

bool staticSharedStack::Pop1(ElemType &x) {
    if (S.top1 == defaultNum){
        return false;
    }
    x = S.data[S.top1++];
    return true;
}

bool staticSharedStack::GetTop0(ElemType &x) const {
    if (S.top0 == -1){
        return false;
    }
    x = S.data[S.top0];
    return true;
}

bool staticSharedStack::GetTop1(ElemType &x) const {
    if (S.top1 == defaultNum){
        return false;
    }
    // 这里的top1指向下一个存储位置 所以栈顶索引为S.top-1
    x = S.data[S.top1 - 1];
    return true;
}
