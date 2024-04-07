/**
 * @Description 删除链表的倒数第N个结点
 * @Version 1.0.0
 * @Date 2024/4/2 10:53
 * @Author Kenton
 */

/*
 * 给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * 输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 */

#include "../head/singleLinkWithHead.h"

ListNode* removeNthFromEnd(singleLink& L, int n){
    ListNode *fast = L.head;
    while (n--){
        fast = fast->next;
    }
    ListNode *slow = L.head;
    ListNode *prev = nullptr;
    while (fast){
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (!prev){
        return L.head->next;
    }
    prev->next = slow->next;
    return L.head;

}

int main(){
    singleLink L;

    L.List_TailInsert();

    ListNode *node = removeNthFromEnd(L, 2);
    L.size--;
    L.printList();
    std::cout << node->data;
}