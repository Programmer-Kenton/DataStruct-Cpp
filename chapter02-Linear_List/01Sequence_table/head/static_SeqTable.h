/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 20:48
 * @Author Kenton
 */

#ifndef STATIC_SEQTABLE_H
#define STATIC_SEQTABLE_H

#include <iostream>
#define defaultNum 10
using ElemType = int;

class static_SeqTable {
public:
    // 静态数组容量
    ElemType data[defaultNum];

    // 数组长度
    int length;

    // 初始化数组
    void InitList();

    // 填充初始化后的顺序便
    void AssignList();

    // 类的构造函数
    static_SeqTable();

    // 在指定位置插入元素
    bool ListInsert(int i,ElemType e);

    // 打印列表的元素
    void printList();

    // 删除指定位置的元素
    bool ListDelete(int i,ElemType &e);

    // 按位查找顺序表的元素
    ElemType GetElem(int i);

    // 按值查找顺序表的元素
    int LocateElem(ElemType e);
};


#endif //STATIC_SEQTABLE_H
