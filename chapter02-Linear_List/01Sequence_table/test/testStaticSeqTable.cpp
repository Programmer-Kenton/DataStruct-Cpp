/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 20:50
 * @Author Kenton
 */

#include "../head/static_SeqTable.h"

int main() {
    static_SeqTable L;
    std::cout << "初始化数组长度为:" << L.length << std::endl;


    // 静态数组无法扩容 容量为10 这里填充9个元素元素
    L.AssignList();

    std::cout << "打印插入元素前数组内容:" << std::endl;
    L.printList();

    L.ListInsert(2,100);

    std::cout << "打印插入后数组内容:" << std::endl;
    L.printList();

    std::cout << "-------------------------------------" << std::endl;

    std::cout << "打印删除元素后数组内容:" << std::endl;

    // 用a存储删除的元素
    ElemType a;
    L.ListDelete(2,a);
    L.printList();
    std::cout << "被删除的元素是:" << a << std::endl;

    std::cout << "打印顺序表第二个元素值:" << L.GetElem(2) << std::endl;


    // 顺序表中没有5的元素 返回值为-1
    std::cout << "顺序表中值为5在第" << L.LocateElem(5) << "个位置";
}
