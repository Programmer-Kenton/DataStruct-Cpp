/**
 * @Description 直接插入排序
 * @Version 1.0.0
 * @Date 2024/4/23 13:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "iostream"
#include "vector"

using namespace std;

void InsertSort(vector<int>& arr){
    int len = arr.size();

    int i,j,temp;
    for (i = 1; i < len; ++i) {
        // 将各元素插入已排好序的序列中
        if (arr[i] <arr[i-1]){
            temp = arr[i];
            // 检查前面所有排好序的元素
            for (j = i - 1;j >= 0 && arr[j] > temp;j--) {
                // 所有大于temp的元素都往后挪位
                arr[j+1] = arr[j];
            }
            // 复制到插入位置
            arr[j+1] = temp;
        }
    }
}

int main(){
    vector<int> arr = {49,28,65,97,76,13,27,49};
    InsertSort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
}