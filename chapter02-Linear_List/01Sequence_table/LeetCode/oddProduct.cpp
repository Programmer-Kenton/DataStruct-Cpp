/**
 * @Description 给定一个数 求这个数里面所有奇数的乘积
 * @Version 1.0.0
 * @Date 2024/3/29 10:58
 * @Author Kenton
 */


#include "../head/dynamic_SeqTable.h"

int main() {
    int n;
    while (std::cin >> n) {
        dynamic_SeqTable L;

        for (int i = 0; i < n + 1; ++i) {
            L.ListInsert(i + 1, i);
        }

        int prod = 1;
        for (int i = 1; i < L.length + 1; ++i) {
            int val = L.GetElem(i);
            if (val % 2 == 1) {
                prod = prod * val;
            }
        }
        std::cout << "奇数相乘值为:" << prod << std::endl;
    }
    return 0;
}
