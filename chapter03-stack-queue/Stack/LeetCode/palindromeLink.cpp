/**
 * @Description 回文链表
 * @Version 1.0.0
 * @Date 2024/4/7 16:14
 * @Author Kenton
 */

#include "iostream"
#include "stack"
#include "D:\C_Study\WorkSpace\Cpp_Study\08DataStruct\chapter02-Linear_List\02Linked_list\SingleLink\head\singleLinkWithHead.h"

bool isPalindrome(singleLink& L){
    std::stack<ListNode*> stk;
    ListNode *temp = L.head->next;
    while (temp){
        stk.push(temp);
        temp = temp->next;
    }
    while (temp){
        if (temp->data != stk.top()->data){
            return false;
        }
        stk.pop();
        temp = temp->next;
    }
    delete temp;
    return true;
}

int main(){
    singleLink L;
    L.List_TailInsert();

    std::cout << isPalindrome(L);
}