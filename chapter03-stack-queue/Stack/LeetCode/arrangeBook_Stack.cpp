/**
 * @Description 图书管理
 * @Version 1.0.0
 * @Date 2024/4/7 15:53
 * @Author Kenton
 */

#include "stack"
#include "D:\C_Study\WorkSpace\Cpp_Study\08DataStruct\chapter02-Linear_List\02Linked_list\SingleLink\head\singleLinkWithHead.h"
#include "vector"

std::vector<int> reverseBookList(singleLink& L){
    std::stack<int> stk;
    while (L.head->next){
        stk.push(L.head->next->data);
        L.head->next = L.head->next->next;
    }
    std::vector<int> ans;
    while (!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main(){
    singleLink L;
    L.List_TailInsert();

    const std::vector<int> &list = reverseBookList(L);

    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << ' ';
    }
}