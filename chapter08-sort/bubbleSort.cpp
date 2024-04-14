/**
 * @Description 冒泡排序
 * @Version 1.0.0
 * @Date 2024/4/13 0:03
 * @Author Kenton
 */

#include "iostream"
#include "vector"

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(std::vector<int>& arr,int length){
    for (int i = 0; i < length - 1; ++i) {
        bool flag = false;
        for (int j = length - 1; j > i; j--) {
            if (arr[j-1] > arr[j]){
                swap(arr[j-1],arr[j]);
                flag = true;
            }
        }
        if (flag == false){
            return;
        }
    }
}


void BubbleSort_2(std::vector<int>& arr,int length){
    for (int i = 0; i < length - 1; ++i) {
        bool flag= false;
        for (int j = 0; j < length - 1 - i; ++j) {
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}