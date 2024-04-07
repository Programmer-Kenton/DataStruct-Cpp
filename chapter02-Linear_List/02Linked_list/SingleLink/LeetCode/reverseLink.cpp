/**
 * @Description 反转链表 递归
 * @Version 1.0.0
 * @Date 2024/4/2 11:29
 * @Author Kenton
 */

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表的头结点

#include "../head/singleLinkWithHead.h"

ListNode* reverseList(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    singleLink L;
    L.List_TailInsert();

    ListNode *pNode = reverseList(L.head);

    L.printList();
}