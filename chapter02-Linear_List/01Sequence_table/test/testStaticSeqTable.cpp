/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 20:50
 * @Author Kenton
 */

#include "../head/static_SeqTable.h"

int main() {
    static_SeqTable L;
    std::cout << "��ʼ�����鳤��Ϊ:" << L.length << std::endl;


    // ��̬�����޷����� ����Ϊ10 �������9��Ԫ��Ԫ��
    L.AssignList();

    std::cout << "��ӡ����Ԫ��ǰ��������:" << std::endl;
    L.printList();

    L.ListInsert(2,100);

    std::cout << "��ӡ�������������:" << std::endl;
    L.printList();

    std::cout << "-------------------------------------" << std::endl;

    std::cout << "��ӡɾ��Ԫ�غ���������:" << std::endl;

    // ��a�洢ɾ����Ԫ��
    ElemType a;
    L.ListDelete(2,a);
    L.printList();
    std::cout << "��ɾ����Ԫ����:" << a << std::endl;

    std::cout << "��ӡ˳���ڶ���Ԫ��ֵ:" << L.GetElem(2) << std::endl;


    // ˳�����û��5��Ԫ�� ����ֵΪ-1
    std::cout << "˳�����ֵΪ5�ڵ�" << L.LocateElem(5) << "��λ��";
}
