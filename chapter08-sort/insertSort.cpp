/**
 * @Description 直接插入排序
 * @Version 1.0.0
 * @Date 2024/4/12 22:55
 * @Author Kenton
 */

#include "iostream"
#include "vector"

void InsertSort(std::vector<int>& arr,int length) {
    int i,j,temp;
    for (i = 1; i < length; ++i) {
        if (arr[i] < arr[i-1]){
            temp = arr[i];
            // 检查所有前面已排好序的元素
            for (j = i-1;j >=0 && arr[j] > temp;--j) {
                // 所有大于temp的元素都想后挪位
                arr[j+1] = arr[j];
            }
            // 复制到插入位置
            arr[j+1] = temp;
        }
    }
}

int main(){
    std::vector<int> arr = {38,49,65,97,13,27,49};


    arr.insert(arr.begin() + 2,100);

    arr.erase(arr.begin() + 2);

    int length = arr.size();


    InsertSort(arr,length);

    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << ' ';
    }

}