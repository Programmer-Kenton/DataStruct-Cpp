/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 12:57
 * @Author Kenton
 */

#include "../head/LinkStack.h"

int main(){
    LinkStack S;

    for (int i = 1; i <= 5; ++i) {
        if (S.push_linkStack(i)){
            std::cout << i << " pushed successfully" << std::endl;
        } else{
            std::cout << "Failed to push" << i << std::endl;
        }
    }

    ElemType e;
    if (S.GetTop(e)){
        std::cout << "Top Element " << e << std::endl;
    }

    while (!S.LinkStackEmpty()){
        ElemType popE;
        if (S.pop_linkStack(popE)){
            std::cout << popE << " popped" << std::endl;
        } else{
            std::cout << "Failed to pop element" << std::endl;
        }
    }

    if (S.LinkStackEmpty()){
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    if (S.push_linkStack(100)){
        std::cout << "100 pushed successfully." << std::endl;
    } else {
        std::cout << "Failed to push 100, stack is full!" << std::endl;
    }
}