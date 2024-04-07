/**
 * @Description 二进制链表转整数
 * @Version 1.0.0
 * @Date 2024/4/1 21:16
 * @Author Kenton
 */

/**
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。
 **/


#include "../head/singleLinkWithHead.h"


int getDecimalValue(singleLink L){
    int sum = 0;
    while (L.head){
        sum = sum * 2 + L.head->data;
        L.head = L.head->next;
    }
    return sum;
}
int main(){

    singleLink L;
    L.ListInsert(1,1);
    L.ListInsert(2,0);
    L.ListInsert(3,1);
    L.ListInsert(4,1);

    std::cout << getDecimalValue(L) << std::endl;
}