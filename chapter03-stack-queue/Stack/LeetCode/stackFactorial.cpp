/**
 * @Description 递归阶乘
 * @Version 1.0.0
 * @Date 2024/4/11 16:38
 * @Author Kenton
 */

#include "iostream"

unsigned long long factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){

    unsigned long long int res = factorial(8);
    std::cout << res << std::endl;
}