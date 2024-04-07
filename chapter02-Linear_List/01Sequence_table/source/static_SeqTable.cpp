/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/3/27 20:48
 * @Author Kenton
 */

#include "../head/static_SeqTable.h"


void static_SeqTable::InitList(){
    // 数组元素都置为0
    for (int i = 0; i < MaxSize; ++i) {
        this->data[i] = 0;
    }
    // 初始化数组长度为0
    this->length = 0;
}

// // 静态数组无法扩容 容量为10 这里填充9个元素元素
void static_SeqTable::AssignList() {
    for (int i = 0; i < MaxSize - 1; ++i) {
        this->data[i] = i;
        this->length++;
    }
}

static_SeqTable::static_SeqTable() {
    InitList();
}

bool static_SeqTable::ListInsert(int i, ElemType e) {
    // 静态数组无法扩容 插入之前判断是否超过最大容量
    if ((this->length + 1) > MaxSize) {
       throw "array is full...";
    }

    // 判断插入的数组下标是否合法
    if (i < 1 || i > this->length + 1) {
        std::cerr << "subscript is invalid";
        return false;
    }

    // 将第i个元素之后的元素后移
    for (int j = this->length; j >= i; --j) {
        this->data[j] = this->data[j-1];
    }
    this->data[i-1] = e;
    this->length++;
    return true;
}

void static_SeqTable::printList() {
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl;
}

bool static_SeqTable::ListDelete(int i, ElemType& e) {
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

ElemType static_SeqTable::GetElem(int i) {
    return this->data[i-1];
}

int static_SeqTable::LocateElem(ElemType e) {
    for (int i = 0; i < this->length; ++i) {
        if (this->data[i] == e) {
            return i + 1;
        }
    }
    // 表示没有查找到
    return -1;
}
