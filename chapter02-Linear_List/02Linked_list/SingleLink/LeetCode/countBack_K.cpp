/**
 * @Description 返回倒数第k个结点的值
 * @Version 1.0.0
 * @Date 2024/4/2 8:55
 * @Author Kenton
 */

/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

        示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。
 */

#include "../head/singleLinkWithHead.h"

ElemType kthToLast(singleLink& L,int k){
   ListNode *fast = L.head;
    while (k--){
        fast = fast->next;
    }
    ListNode *slow = L.head;
    while (fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

int main(){
    singleLink L;
    L.List_TailInsert();
    L.printList();

    std::cout << kthToLast(L,3);
}