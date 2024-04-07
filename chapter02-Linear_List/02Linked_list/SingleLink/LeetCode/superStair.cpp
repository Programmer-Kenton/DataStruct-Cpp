/**
 * @Description 超级楼梯
 *
 * 一种阶梯共M级 刚开始在1级 每次只能上去1级或者2级 要走上第M级 有多少种走法
 * @Version 1.0.0
 * @Date 2024/4/1 21:02
 * @Author Kenton
 */

#include "../head/singleLinkWithHead.h"

int main(){
    singleLink L;

    L.ListInsert(1,1);
    L.ListInsert(2,1);
    L.ListInsert(3,1);

    for (int i = 3; i <= 40 ; ++i) {
        ListNode *a = L.GetNode(i - 1);
        ListNode *b = L.GetNode(i - 2);
        L.ListInsert(i,a->data + b->data);
    }
    L.printList();

    int n;
    std::cin >> n;
    while (n--){
        int x;
        std::cin >> x;
        std::cout << L.GetElem(x) << std::endl;
    }
}