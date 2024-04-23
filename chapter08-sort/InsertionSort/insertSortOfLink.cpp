/**
 * @Description 链表的插入排序
 * @Version 1.0.0
 * @Date 2024/4/23 15:02
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "iostream"
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int data):data(data),next(nullptr){}
};

ListNode* insertionSortList(ListNode *head){
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *start = new ListNode(0);
    start->next = head;
    ListNode *prev = head,*curr = head->next;
    while (curr != nullptr){
        if (prev->data <= curr->data){
            prev = prev->next;
            curr = curr->next;
        } else{
            ListNode *temp = start;
            while (temp->next->data < curr->data){
                temp = temp->next;
            }

            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = prev->next;
        }
    }
    return start->next; // 返回排序后链表的头指针
}

// 打印链表
void printList(ListNode *head) {
    ListNode *temp = head; // 使用临时指针遍历链表
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    // 创建链表
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    // 对链表进行插入排序
    head = insertionSortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
