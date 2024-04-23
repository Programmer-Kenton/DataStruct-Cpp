/**
 * @Description 带哨兵的折半插入排序
 * @Version 1.0.0
 * @Date 2024/4/23 14:48
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "iostream"
#include "vector"

using namespace std;

void InsertSort(vector<int>& arr){
    int low,high,mid;
    int len = arr.size();
    for (int i = 2; i < len; ++i) {
        arr[0] = arr[i];
        // 设置折半查找范围
        low = 1,high = i - 1;
        while (low <= high){
            mid = (low + high) / 2;
            if (arr[mid] > arr[0]) high = mid - 1;
            else low = mid + 1;
        }

        for (int j = i - 1; j >= high + 1; --j) {
            arr[j+1] = arr[j];
        }
        arr[high+1] = arr[0];
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