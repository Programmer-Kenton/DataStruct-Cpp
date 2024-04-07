/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/6 16:06
 * @Author Kenton
 */
#include "../head/staticLinkWithHead.h"

staticLinkWithHead::staticLinkWithHead() {
    // 头结点指向数组的第一个元素
    head = &space[0];
    for (int i = 0; i < MaxSize - 1; ++i) {
        // 初始化空闲静态链表
        space[i].next = i + 1;
    }
    // 最后一个结点的next为-1 表示空闲链表结束
    space[MaxSize - 1].next = -1;
    // 初始时没有空闲结点
    free = 0;
}

void staticLinkWithHead::InitList() {
   // 初始化时链表为空
   head->next = -1;
   // 没有空闲结点
   free = 0;
}

bool staticLinkWithHead::ListInsert(int i, ElemType e) {
    if (i < 1 || i > MaxSize || free == -1){
        // 插入位置不合法或链表已满
        return false;
    }
    // j为前一个结点的位置
    int j = MaxSize - 1;
    // 如果链表为空
    if (head->next == -1){
        // 空闲结点作为第一个结点
        j = free;
    } else{
        // 找到第i-1个结点的位置
        for (int k = 0; k < i - 1; ++k) {
            j = space[j].next;
        }
    }
    // p为新结点的位置
    int p = free;
    space[p].data = e;
    space[p].next = space[j].next;
    space[j].next = p;
    free = space[p].next;
    return true;
}

bool staticLinkWithHead::ListDelete(int i) {
    if (i < 1 || head->next == -1) {
        return false; // 删除位置不合法或链表为空
    }
    int j = MaxSize - 1; // j为前一个结点的位置
    for (int k = 0; k < i - 1; k++) {
        j = space[j].next;
    }
    if (j == -1 || space[j].next == -1) {
        return false; // 第i个结点不存在
    }
    int q = space[j].next; // q为要删除结点的位置
    space[j].next = space[q].next; // 修改前驱结点的next
    space[q].next = free; // 将要删除的结点加入到空闲链表
    free = q; // 更新空闲链表的头结点位置
    return true;
}

void staticLinkWithHead::printList() {
    int p = head->next;
    while (p != -1) {
        std::cout << space[p].data << " ";
        p = space[p].next;
    }
    std::cout << std::endl;
}
