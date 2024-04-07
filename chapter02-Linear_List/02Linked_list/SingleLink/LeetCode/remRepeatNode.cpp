/**
 * @Description 移除重复结点
 * @Version 1.0.0
 * @Date 2024/4/2 11:04
 * @Author Kenton
 */

/*
 *
 * 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
 */

#include "../head/singleLinkWithHead.h"

ListNode* removeDuplicateNodes(singleLink& L){
    if (L.head == nullptr){
        return nullptr;
    }
    bool hash[200] = {0};
    ListNode *temp = L.head;
    ListNode *prev = L.head;
    ListNode *curr = L.head->next;
    hash[L.head->data] = 1;
    while (curr){
        if (!hash[curr->data]){
            hash[curr->data] = 1;
            temp->next = curr;
            temp = temp->next;
        } else{
            L.size--;
        }
        prev = curr;
        curr = curr->next;
    }
    temp->next = nullptr;
    return L.head;
}

int main(){
    singleLink L;
    L.List_TailInsert();
    removeDuplicateNodes(L);
    L.printList();
}