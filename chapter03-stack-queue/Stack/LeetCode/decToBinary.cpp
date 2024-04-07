/**
 * @Description 十进制转二进制
 * @Version 1.0.0
 * @Date 2024/4/7 15:28
 * @Author Kenton
 */

#include "../head/LinkStack.h"

int main(){
    int n;
    while (std::cin >> n){
        LinkStack S;
        while (n){
            S.push_linkStack(n % 2);
            n = n / 2;
        }
        while (S.size){
            ElemType e;
            S.pop_linkStack(e);
            std::cout << e;
        }
        std::cout << std::endl;
    }
}