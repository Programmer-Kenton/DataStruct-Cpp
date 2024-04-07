/**
 * @Description 删除排序链表中重复的元素
 * @Version 1.0.0
 * @Date 2024/4/2 10:36
 * @Author Kenton
 */

/*
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 *
 *
 * 输入：head = [1,1,2]
输出：[1,2]
 * */

#include "../head/singleLinkWithHead.h"

ListNode* deleteDuplicates(singleLink& L){
    ListNode *prev = nullptr;
    ListNode *curr = L.head;

    while (curr){
        while (prev && prev->data == curr->data){
            prev->next = curr->next;
            curr = prev->next;
            L.size--;
            if (!curr){
                break;
            }
        }
        if (!curr){
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return L.head;
}

int main(){
    singleLink L;
    L.List_TailInsert();

    deleteDuplicates(L);
    L.printList();
}