/**
 * @Description 链表的中间结点
 * @Version 1.0.0
 * @Date 2024/4/2 9:40
 * @Author Kenton
 */

/*
 * 给你单链表的头结点 head ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。
 */

#include "../head/singleLinkWithHead.h"

ListNode* middleNode(singleLink L){
    ListNode *fast = L.head;
    ListNode *slow = L.head;
    while (fast){
        fast = fast->next;
        if (fast == nullptr){
            return slow;
        }
        fast = fast->next;
        if (fast == nullptr){
            // 有两个中间结点 则返回第二个
            return slow->next;
        }
        slow = slow->next;
    }
}

int main(){
    singleLink L;

    L.List_TailInsert();

    ListNode *temp = middleNode(L);
    std::cout << temp->data;

    delete[] temp;
}

