/**
 * @Description 图书整理1
 * @Version 1.0.0
 * @Date 2024/4/2 11:14
 * @Author Kenton
 */


/*
 * 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。
 * 为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。



示例 1：

输入：head = [3,6,4,1]

输出：[1,4,6,3]
 */

#include "../head/singleLinkWithHead.h"
#include "vector"


std::vector<int> reverseBookList(singleLink& L,std::vector<int>& ans){
    ListNode *tmp = L.head->next;
    while (tmp){
        ans.push_back(tmp->data);
        tmp = tmp->next;
    }
    delete tmp;
    int left = 0,right = ans.size() - 1;
    while (left < right){
        int temp = ans[left];
        ans[left] = ans[right];
        ans[right] = temp;
        ++left;
        --right;
    }
    return ans;
}

int main(){
    singleLink L;

    L.List_TailInsert();

    std::vector<int> ans;

    reverseBookList(L,ans);

    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << ' ';
    }
}