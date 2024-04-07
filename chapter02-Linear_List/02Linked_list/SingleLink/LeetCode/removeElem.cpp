/**
 * @Description 移除链表元素
 * @Version 1.0.0
 * @Date 2024/4/2 10:03
 * @Author Kenton
 */

/*
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]
 */

#include "../head/singleLinkWithHead.h"

ListNode* removeElements(singleLink& L, int val){
    ListNode *newHead = new ListNode(NULL);
    newHead->next = L.head;
    ListNode *pre = newHead;
    while (pre->next){
        if (pre->next->data == val){
            pre->next = pre->next->next;
            L.size--;
        } else{
            pre = pre->next;
        }
    }
    return newHead->next;
}

int main(){

    singleLink L;

    L.List_TailInsert();

    removeElements(L,6);

    L.printList();
}