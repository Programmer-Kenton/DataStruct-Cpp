/**
 * @Description 数列求和
 * @Version 1.0.0
 * @Date 2024/4/1 20:19
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

int main(){
    int n;
    while (std::cin >> n){
        singleLink L;
        // 这里的i从1开始
        for (int i = 1; i < n + 1; ++i) {
            int x;
            std::cin >> x;
            L.ListInsert(i,x);
        }
        L.printList();
        std::cout << L.Sum() << std::endl;
    }
}