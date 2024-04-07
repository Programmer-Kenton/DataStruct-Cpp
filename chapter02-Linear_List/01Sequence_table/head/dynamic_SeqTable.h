/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 21:51
 * @Author Kenton
 */

#ifndef DYNAMIC_SEQTABLE_H
#define DYNAMIC_SEQTABLE_H
#include <iostream>
#define InitSize 10
using ElemType = int;

class dynamic_SeqTable {
public:
    // 动态分配数组内存的指针
    ElemType* data;
    // 顺序表的最大容量
    int MaxSize;
    // 顺序表的当前长度
    int length;


    // 初始化动态数组
    void InitList();

    // 填充初始化后的顺序
    void AssignList();

    // 构造函数
    dynamic_SeqTable();

    // 根据传入的len增加动态数组的容量
    void IncreaseSize(int len);

    // 数组动态扩容两倍
    void IncreaseSizeDouble();

    // 在指定位置插入元素
    bool ListInsert(int i,ElemType e);

    // 删除指定位置的元素
    bool ListDelete(int i,ElemType &e);

    // 按位查找顺序表的元素
    ElemType GetElem(int i);

    // 按值查找顺序表的元素
    int LocateElem(ElemType e);

    // 打印列表的元素
    void printList();
};




#endif //DYNAMIC_SEQTABLE_H
