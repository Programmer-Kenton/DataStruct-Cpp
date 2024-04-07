/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/30 12:38
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

int main() {
    singleLink L;

    // 1.带头结点的单链表初始化时生成头结点 因此头结点不为空
    if (L.head != NULL) {
        std::cout << "success" << std::endl;
    }

    // 2.判断是否为空
    std::cout << "初始化后的单链表是否为空:" << L.isEmpty() << std::endl;

    // 3.在第一个位置插入 123
    L.ListInsert(1,123);
    // 第二个位置插入 456
    L.ListInsert(2,456);
    // 第三个位置插入 789
    L.ListInsert(3,789);

    // 4.打印测试 按位插入接口和打印接口
    std::cout << "插入数据后的链表:";
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 5.后插测试 在第二个位置后面插入444
    // 先找到第二个位置的结点 测试查找结点函数
    ListNode *node = L.GetNode(2);
    L.InsertNextNode(node,444);
    // 打印插入结点后的链表
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 6.删除第4个位置的元素 并用temp接收
    int temp;
    L.ListDelete(4,temp);
    std::cout << "temp = " << temp << std::endl;
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 7.测试在第三个位置前面插入数据555
    ListNode *node2 = L.GetNode(3);
    L.InsertPriorNode(node2,555);
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 删除指定结点
    L.DeleteNode(node2);
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 8.查找指定结点的元素值
    int value = L.GetElem(2);
    std::cout << "value = " << value << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 9.按值查找 找到数据为e的结点
    ListNode *node3 = L.LocateNode(123);
    std::cout << "node3.data = " << node3->data << std::endl;

    // 10.测试链表逆置
    std::cout << "-------------------------逆置前----------------------------------------" << std::endl;
    L.printList();

    std::cout << "-------------------------逆置后----------------------------------------" << std::endl;
    L.List_Inverse();
    L.printList();
}
