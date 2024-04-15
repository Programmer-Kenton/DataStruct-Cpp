/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 17:02
 * @Author Kenton
 */

#include "../head/staticQueue.h"

int main(){
    staticQueue Q;

    for (int i = 0; i < defaultNum; ++i) {
        if (!Q.EnQueue(i)){
            std::cout << "Queue is full,can't enqueue" << i << std::endl;
            break;
        }
    }

    std::cout << "Queue is full:" << Q.isFull() << std::endl;

    for (int i = 0; i < defaultNum; ++i) {
        ElemType x;
        if (Q.DeQueue(x)){
            std::cout << "Dequeued:" << x << std::endl;
        } else{
            std::cout << "Queue is empty,can't dequeue" << std::endl;
            break;
        }
    }

    if (Q.EnQueue(defaultNum)){
        std::cout << "Enqueue:" << defaultNum << std::endl;
    } else{
        std::cout << "Failed to enqueued" << defaultNum << ",queue is full" << std::endl;
    }

    std::cout << "Queue size:" << Q.getSize() << std::endl;
}