/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 21:52
 * @Author Kenton
 */


#include "../head/dynamic_SeqTable.h"

int main() {
    dynamic_SeqTable L;

    // ˳���ֵ
    L.AssignList();

    std::cout << "��ӡ��ֵ���˳���:";
    L.printList();

    L.ListInsert(9, 100);

    std::cout << "��ӡ�ڵ�9��λ��ִ�в�����˳���:";
    L.printList();

    // ɾ����9��λ�õ�Ԫ�ز�����
    int res = 0;
    L.ListDelete(9,res);
    std::cout << "���ص�res = " << res << std::endl;

    // ���ҵ����Ԫ��ֵ
    std::cout << L.LocateElem(5) << std::endl;

    // ����ֵΪ2��Ԫ���±�
    std::cout << L.GetElem(2) << std::endl;
}
