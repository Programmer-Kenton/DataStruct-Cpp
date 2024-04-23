/**
 * @Description 不带哨兵的折半插入排序
 * @Version 1.0.0
 * @Date 2024/4/23 14:57
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <iostream>
#include <vector>
using namespace std;

void BinaryInsertSort(vector<int>& arr){
    int len = arr.size();
    for (int i = 1; i < len; i++) {
        int low = 0, high = i - 1;
        int key = arr[i];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // 将插入位置之后的元素都后移一位
        for (int j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        } // 插入待排序元素到正确位置
        arr[low] = key;
    }
}

int main(){
    vector<int> arr = {49, 28, 65, 97, 76, 13, 27, 49};
    BinaryInsertSort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}
