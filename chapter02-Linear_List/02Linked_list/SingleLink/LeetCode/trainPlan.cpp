/**
 * @Description 训练计划2
 * @Version 1.0.0
 * @Date 2024/4/2 9:13
 * @Author Kenton
 */


/*
 * 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。



示例 1：

输入：head = [2,4,7,8], cnt = 1
输出：8*/

#include "../head/singleLinkWithHead.h"

ListNode* trainingPlan(singleLink& L, int cnt){
    ListNode *fast = L.head;
    while (cnt--){
        fast = fast->next;
    }
    ListNode *slow = L.head;
    while (fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){

    singleLink L;

    L.List_HeadInsert();

    L.printList();

    ListNode *temp = trainingPlan(L, 3);

    // 把查找到的结点删除掉 再打印测试trainingPlan接口
    L.DeleteNode(temp);

    L.printList();
}