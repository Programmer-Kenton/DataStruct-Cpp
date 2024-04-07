/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/7 14:26
 * @Author Kenton
 */

#include "../head/staticStack_Hero.h"

//template<typename T>
//void staticStack_Hero<T>::resize(){
//    int newCapacity = capacity * 2;
//    T *newData = new T[newCapacity];
//    for (int i = 0; i < size; ++i) {
//        newData[i] = data[i];
//    }
//    delete[] data;
//    data = newData;
//    capacity = newCapacity;
//}
//
//template<typename T>
//staticStack_Hero<T>::~staticStack_Hero() {
//    delete[] data;
//}
//
//template<typename T>
//void staticStack_Hero<T>::push(T element) {
//    if (size == capacity){
//        resize();
//    }
//    data[size++] = element;
//}
//
//template<typename T>
//T staticStack_Hero<T>::pop() {
//    if (size == 0){
//        throw std::underflow_error("Stack is empty");
//    }
//    return data[--size];
//}
//
//template<typename T>
//T staticStack_Hero<T>::top() const {
//    if (size == 0){
//        throw std::underflow_error("Stack is empty");
//    }
//    return data[size-1];
//}
//
//template<typename T>
//int staticStack_Hero<T>::getSize() const {
//    return size;
//}