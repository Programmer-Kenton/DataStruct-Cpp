/**
 * @Description ��ֵͳ�� ͳ��˳�������������������ĸ���
 * @Version 1.0.0
 * @Date 2024/3/29 11:35
 * @Author Kenton
 */

#include "../head/static_SeqTable.h"

int main() {
    static_SeqTable L;

    // ��̬���������9��Ԫ��
    L.AssignList();

    int zero = 0;
    int posNum = 0;
    int negNum = 0;

    for (int i = 1; i < L.length + 1; ++i) {
       if (L.GetElem(i) > 0) {
           posNum++;
       }else if (L.GetElem(i) < 0) {
           negNum++;
       }else {
           zero++;
       }
    }

    std::cout << "����:" << posNum << ' ' << "����:" << negNum << ' ' << "��:" << zero;
}
