/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/30 12:38
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

int main() {
    singleLink L;

    // 1.��ͷ���ĵ������ʼ��ʱ����ͷ��� ���ͷ��㲻Ϊ��
    if (L.head != NULL) {
        std::cout << "success" << std::endl;
    }

    // 2.�ж��Ƿ�Ϊ��
    std::cout << "��ʼ����ĵ������Ƿ�Ϊ��:" << L.isEmpty() << std::endl;

    // 3.�ڵ�һ��λ�ò��� 123
    L.ListInsert(1,123);
    // �ڶ���λ�ò��� 456
    L.ListInsert(2,456);
    // ������λ�ò��� 789
    L.ListInsert(3,789);

    // 4.��ӡ���� ��λ����ӿںʹ�ӡ�ӿ�
    std::cout << "�������ݺ������:";
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 5.������ �ڵڶ���λ�ú������444
    // ���ҵ��ڶ���λ�õĽ�� ���Բ��ҽ�㺯��
    ListNode *node = L.GetNode(2);
    L.InsertNextNode(node,444);
    // ��ӡ������������
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 6.ɾ����4��λ�õ�Ԫ�� ����temp����
    int temp;
    L.ListDelete(4,temp);
    std::cout << "temp = " << temp << std::endl;
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 7.�����ڵ�����λ��ǰ���������555
    ListNode *node2 = L.GetNode(3);
    L.InsertPriorNode(node2,555);
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // ɾ��ָ�����
    L.DeleteNode(node2);
    L.printList();

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 8.����ָ������Ԫ��ֵ
    int value = L.GetElem(2);
    std::cout << "value = " << value << std::endl;

    std::cout << "-----------------------------------------------------------------" << std::endl;

    // 9.��ֵ���� �ҵ�����Ϊe�Ľ��
    ListNode *node3 = L.LocateNode(123);
    std::cout << "node3.data = " << node3->data << std::endl;

    // 10.������������
    std::cout << "-------------------------����ǰ----------------------------------------" << std::endl;
    L.printList();

    std::cout << "-------------------------���ú�----------------------------------------" << std::endl;
    L.List_Inverse();
    L.printList();
}
