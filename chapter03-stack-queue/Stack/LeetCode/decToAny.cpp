/**
 * @Description 十进制转任意进制
 * @Version 1.0.0
 * @Date 2024/4/7 15:40
 * @Author Kenton
 */

#include "../head/LinkStack.h"

int main(){
    int N,x;
    while (std::cin >> N >> x){
        if (N == 0){
            std::cout << 0 << std::endl;
            continue;
        }
        if (N < 0){
            std::cout << '-';
            N = -N;
        }
        LinkStack S;
        while (N){
            S.push_linkStack(N % x);
            N = N / x;
        }
        while (S.size){
            ElemType x;
            S.pop_linkStack(x);
            if (x >= 10){
                printf("%c",'A' + x - 10);
            } else{
                printf("%d",x);
            }
        }
        std::cout << std::endl;
    }
}