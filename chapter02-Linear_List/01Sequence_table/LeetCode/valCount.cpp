/**
 * @Description 数值统计 统计顺序表中正数、负数、零的个数
 * @Version 1.0.0
 * @Date 2024/3/29 11:35
 * @Author Kenton
 */

#include "../head/static_SeqTable.h"

int main() {
    static_SeqTable L;

    // 静态数组填充了9个元素
    L.AssignList();

    int zero = 0;
    int posNum = 0;
    int negNum = 0;

    for (int i = 1; i < L.length + 1; ++i) {
       if (L.GetElem(i) > 0) {
           posNum++;
       }else if (L.GetElem(i) < 0) {
           negNum++;
       }else {
           zero++;
       }
    }

    std::cout << "正数:" << posNum << ' ' << "负数:" << negNum << ' ' << "零:" << zero;
}
