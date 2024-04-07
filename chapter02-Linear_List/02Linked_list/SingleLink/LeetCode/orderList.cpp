/**
 * @Description 有序数列
 * @Version 1.0.0
 * @Date 2024/4/1 20:29
 * @Author Kenton
 */

#include "iostream"
#include "../head/singleLinkWithHead.h"

int main(){
    int n,x;

    while (std::cin >> n >> x){
        if (!n && !x){
            break;
        }
        singleLink L;
        // 我们设计的接口只能从1位置开始插入 这里设置size为1 为了后面的插入操作
        L.size = 1;
        while (n--){
            int value;
            std::cin >> value;
            L.append(value);
        }
        L.ascInsert(x);
        // 实际尺寸为4 打印出来是5 因为我们前面size从1开始
        L.printList();
    }
}