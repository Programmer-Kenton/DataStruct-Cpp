/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 21:51
 * @Author Kenton
 */

#include "../head/dynamic_SeqTable.h"

#include <iostream>
#include <wchar.h>

void dynamic_SeqTable::InitList() {
    this->data = new ElemType[InitSize];
    this->length = 0;
    this->MaxSize = InitSize;
}

void dynamic_SeqTable::AssignList() {
    for (int i = 0; i < this->MaxSize; ++i) {
        this->data[i] = i;
        this->length++;
    }
}

dynamic_SeqTable::dynamic_SeqTable() {
    InitList();
}

void dynamic_SeqTable::IncreaseSize(int len) {
    // 新数组的容量
    int newMaxSize = this->MaxSize + len;
    // 申请新的指针
    ElemType *newData = new ElemType[newMaxSize];
    if (!newData) {
        throw "Failed to allocate memory...";
    }
    // 将原来指针指向的地址的数组内容复制到新数组
    for (int i = 0; i < this->length; ++i) {
        newData[i] = this->data[i];
    }
    // 释放原先指针指向的内存空间
    delete[] this->data;
    // 将新指针复制给data
    this->data = newData;
    // 更新数组的容量
    this->MaxSize = newMaxSize;
}

void dynamic_SeqTable::IncreaseSizeDouble() {
    int newSize = this->MaxSize * 2;
    ElemType *newData = new ElemType[newSize];
    if (!newData) {
        throw "Failed to allocate memory...";
    }
    for (int i = 0; i < this->length; ++i) {
        newData[i] = this->data[i];
    }
    delete[] data;
    this->data = newData;
    this->MaxSize = newSize;
}

bool dynamic_SeqTable::ListInsert(int i, ElemType e) {
    if ((this->length + 1) > this->MaxSize) {
        // 申请扩容 默认扩容为原来数组容量的两倍
        IncreaseSizeDouble();
    }

    // 判断插入的数组下标是否合法
    if (i < 1 || i > this->length + 1) {
        throw "subscript is invalid";
    }

    // 将第i个元素之后的元素后移
    for (int j = this->length; j >= i; --j) {
        this->data[j] = this->data[j-1];
    }
    this->data[i-1] = e;
    this->length++;
    return true;

}

bool dynamic_SeqTable::ListDelete(int i, ElemType& e) {
    if (i < 1 || i > this->length) {
        std::cerr << "subscript is invalid";
        return false;
    }
    e = this->data[i-1];
    for (int j = i; j < this->length; ++j) {
        this->data[j-1] = this->data[j];
    }
    this->length--;
    return true;
}

ElemType dynamic_SeqTable::GetElem(int i) {
    return this->data[i-1];
}

int dynamic_SeqTable::LocateElem(ElemType e) {
    for (int i = 0; i < this->length; ++i) {
        if (this->data[i] == e) {
            return i + 1;
        }
    }
    // 表示没有查找到
    return -1;
}

void dynamic_SeqTable::printList() {
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl;
}
