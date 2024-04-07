/**
 * @Description 删除中间结点
 * @Version 1.0.0
 * @Date 2024/4/2 9:58
 * @Author Kenton
 */

/*
 * 若链表中的某个节点，既不是链表头节点，也不是链表尾节点，则称其为该链表的「中间节点」。

假定已知链表的某一个中间节点，请实现一种算法，将该节点从链表中删除。

例如，传入节点 c（位于单向链表 a->b->c->d->e->f 中），将其删除后，剩余链表为 a->b->d->e->f



示例：

输入：节点 5 （位于单向链表 4->5->1->9 中）
输出：不返回任何数据，从链表中删除传入的节点 5，使链表变为 4->1->9
 */

#include "../head/singleLinkWithHead.h"


void deleteNode(singleLink& L, ListNode* node){
    L.DeleteNode(node);
}

int main(){
    singleLink L;
    L.List_TailInsert();

    ListNode *node = L.GetNode(1);
    deleteNode(L,node);

    L.printList();
}