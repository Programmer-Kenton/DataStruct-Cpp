/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 22:09
 * @Author Kenton
 */

#include "../head/doublePointLinkQueueWithoutHead.h"

int main(){
    doublePointLinkQueueWithoutHead queue;
    ElemType x;

    // 插入元素
    queue.EnQueueFront(1);
    queue.EnQueueRear(2);
    queue.EnQueueFront(3);

    // 删除元素
    queue.DeQueueFront(x);
    std::cout << "Deleted element from front: " << x << std::endl;

    queue.DeQueueRear(x);
    std::cout << "Deleted element from rear: " << x << std::endl;

    // 判断队列是否为空
    if (queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }
}