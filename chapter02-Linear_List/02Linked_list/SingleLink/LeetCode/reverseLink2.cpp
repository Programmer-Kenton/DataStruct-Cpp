/**
 * @Description 反转链表 迭代
 * @Version 1.0.0
 * @Date 2024/4/7 10:23
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

ListNode* reverseList(ListNode* head){
    ListNode *curr = head->next;
    ListNode *prev = nullptr;
    ListNode *next;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
    return head;
}

int main(){
    singleLink L;
    L.List_TailInsert();
    ListNode *pNode = reverseList(L.head);
    L.head = pNode;
    L.printList();
}