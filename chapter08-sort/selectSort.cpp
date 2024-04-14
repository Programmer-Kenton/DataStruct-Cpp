/**
 * @Description TODO 选择排序
 * @Version 1.0.0
 * @Date 2024/4/13 0:24
 * @Author Kenton
 */

#include "iostream"
#include "vector"

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

void SelectSort(std::vector<int>& arr,int length){
    // 一共n-1趟
    for (int i = 0; i < length - 1; ++i) {
        // 记录最小元素位置
        int min = i;
        // 在A[i...n-1]中选择最小的元素
        for (int j = i + 1; j < length; ++j) {
            // 更新最小元素位置
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i){
            swap(arr[i],arr[min]);
        }
    }
}