/**
 * @Description 直接插入排序 带哨兵
 * @Version 1.0.0
 * @Date 2024/4/23 14:05
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "iostream"
#include "vector"

using namespace std;

void InsertSort(vector<int>& arr){
    int len = arr.size();
    for (int i = 2; i < len; ++i) {
        if (arr[i] < arr[i-1]){
            // 暂存待排序的元素
            arr[0] = arr[i];
            int j;
            // 在有序部分从后往前查找合适位置并移动元素
            for (j = i - 1;arr[j] > arr[0];--j) {
                arr[j+1] = arr[j];
            }
            // 插入待排序元素到正确位置
            arr[j+1] = arr[0];
        }
    }
}

int main(){
    vector<int> arr = {0, 49, 28, 65, 97, 76, 13, 27, 49};
    InsertSort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}
