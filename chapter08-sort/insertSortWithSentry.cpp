/**
 * @Description TODO 带哨兵的直接插入
 * @Version 1.0.0
 * @Date 2024/4/12 23:20
 * @Author Kenton
 */

#include "iostream"
#include "vector"

void InsertSort(std::vector<int> arr,int length){
    int i,j;
    for (i = 2;i <= length; i++) {
        if (arr[i] < arr[i - 1]){
            // 复制为哨兵 arr[0]不存放元素
            arr[0] = arr[i];
            // 从后往前查找待插入位置
            for (j = i - 1;arr[0] < arr[j];j--) {
                // 向后挪位
                arr[j+1] = arr[j];
            }
            // 复制到插入位置
            arr[j+1] = arr[0];
        }
    }
}