/**
 * @Description TODO 希尔排序
 * @Version 1.0.0
 * @Date 2024/4/12 23:37
 * @Author Kenton
 */

#include "iostream"
#include "vector"

void ShellSort(std::vector<int> &arr, int length) {
    int d, i, j;
    // arr[0]只是暂存单元 不是哨兵 当j<=0 插入位置已到
    // 步长变化
    for (d = length / 2; d >= 1; d = d / 2) {
        for (i = d + 1; i <= length; ++i) {
            // 需要将arr[i]插入有序增量子表
            if (arr[i] < arr[i-d]){
                arr[0] = arr[i];
                for (j = i - d; j > 0 && arr[0] << arr[j]; j -= d) {
                    // 记录后移 查找插入的位置
                    arr[j+d] = arr[j];
                }
                // 插入
                arr[j+d] = arr[0];
            }
        }
    }
}

int main(){
    std::vector<int> arr = {13,49,65,97,76,38,27,49};
    int length = arr.size();

    ShellSort(arr,length);

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
}