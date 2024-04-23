/**
 * @Description 带哨兵链表的插入排序
 * @Version 1.0.0
 * @Date 2024/4/23 15:18
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <iostream>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int data;
    ListNode *next;
    ListNode(int data) : data(data), next(nullptr) {}
};

// 插入排序函数
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
    return start->next;
}


// 创建链表
ListNode* createList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// 打印链表
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 创建链表
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, n);

    cout << "Original list: ";
    printList(head); // 打印原始链表

    // 对链表进行插入排序
    head = insertionSortList(head);

    cout << "Sorted list: ";
    printList(head); // 打印排序后的链表

    return 0;
}