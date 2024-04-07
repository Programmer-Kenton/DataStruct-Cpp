/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 10:46
 * @Author Kenton
 */

#include "../head/staticStack.h"

int main(){
    staticStack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(4);

    int x;

    while (!stack.StackEmpty()){
        stack.Pop(x);
        std::cout << "x = " << x << std::endl;
    }
}