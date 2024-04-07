/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 10:14
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

ListNode* trainningPlan(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *newHead = trainningPlan(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){

}