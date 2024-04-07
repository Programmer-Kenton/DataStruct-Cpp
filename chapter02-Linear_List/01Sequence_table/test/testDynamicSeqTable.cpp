/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 21:52
 * @Author Kenton
 */


#include "../head/dynamic_SeqTable.h"

int main() {
    dynamic_SeqTable L;

    // 顺序表赋值
    L.AssignList();

    std::cout << "打印赋值后的顺序表:";
    L.printList();

    L.ListInsert(9, 100);

    std::cout << "打印在第9个位置执行插入后的顺序表:";
    L.printList();

    // 删除第9个位置的元素并返回
    int res = 0;
    L.ListDelete(9,res);
    std::cout << "返回的res = " << res << std::endl;

    // 查找第五个元素值
    std::cout << L.LocateElem(5) << std::endl;

    // 查找值为2的元素下标
    std::cout << L.GetElem(2) << std::endl;
}
